#include <bits/stdc++.h>
using namespace std;

struct Command {
    int existing, newCube;
    string dir;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Command> cmds(n);
    
    for (int i = 0; i < n; i++)
        cin >> cmds[i].existing >> cmds[i].newCube >> cmds[i].dir;

    int queryCube;
    cin >> queryCube;

    // Step 1: Sort commands
    sort(cmds.begin(), cmds.end(), [](const Command &a, const Command &b) {
        if (a.existing == b.existing) return a.newCube < b.newCube;
        return a.existing < b.existing;
    });

    // Step 2: Coordinate mappings
    map<int, pair<int,int>> cubePos;     // cube -> (x, y)
    map<pair<int,int>, int> posCube;     // (x, y) -> cube

    // Direction mapping
    map<string, pair<int,int>> dirMap = {
        {"top", {0, 1}},
        {"down", {0, -1}},
        {"left", {-1, 0}},
        {"right", {1, 0}}
    };

    // Initializing first cube position safely
    if (!cmds.empty()) {
        cubePos[cmds[0].existing] = {0, 0};
        posCube[{0, 0}] = cmds[0].existing;
    }

    // Step 3: Process commands
    for (auto &c : cmds) {
        // If existing cube has no coordinate yet, skip
        if (!cubePos.count(c.existing)) continue;

        int x = cubePos[c.existing].first;
        int y = cubePos[c.existing].second;
        auto it = dirMap.find(c.dir);
        if (it == dirMap.end()) continue; // invalid direction safeguard

        int dx = it->second.first, dy = it->second.second;
        int nx = x + dx, ny = y + dy;

        // If another cube already exists there, remove it
        if (posCube.count({nx, ny})) {
            int old = posCube[{nx, ny}];
            cubePos.erase(old);
        }

        cubePos[c.newCube] = {nx, ny};
        posCube[{nx, ny}] = c.newCube;
    }

    // Step 4: Output neighbors for queryCube
    if (!cubePos.count(queryCube)) {
        cout << "-1 -1 -1 -1\n";
        return 0;
    }

    int qx = cubePos[queryCube].first, qy = cubePos[queryCube].second;
    vector<pair<int,int>> dirs = {
        {0, 1},   // top
        {0, -1},  // down
        {-1, 0},  // left
        {1, 0}    // right
    };

    for (int i = 0; i < 4; i++) {
        int nx = qx + dirs[i].first, ny = qy + dirs[i].second;
        if (posCube.count({nx, ny})) cout << posCube[{nx, ny}];
        else cout << -1;
        if (i < 3) cout << " ";
    }
    cout << "\n";

    return 0;
}
