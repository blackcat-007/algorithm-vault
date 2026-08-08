#include <bits/stdc++.h>
using namespace std;

struct BrickNode {
    int idx, cost;
    bool operator<(const BrickNode &b) const { return cost > b.cost; } // for min-heap
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> wall(N);
    for (int i = 0; i < N; i++) cin >> wall[i];

    // Grid info
    vector<vector<int>> grid(N, vector<int>(N, -1));
    vector<char> brickKind;
    vector<vector<pair<int,int>>> brickCells;
    int totalBricks = 0;

    // Parse each encoded row
    for (int r = 0; r < N; r++) {
        string &line = wall[r];
        int c = 0;
        for (int p = 0; p < (int)line.size();) {
            int len = 0;
            while (p < (int)line.size() && isdigit(line[p])) {
                len = len * 10 + (line[p] - '0');
                p++;
            }
            if (p >= (int)line.size()) break;
            char typ = line[p++];

            brickKind.push_back(typ);
            brickCells.push_back({});
            int id = totalBricks++;

            for (int k = 0; k < len && c < N; k++) {
                grid[r][c] = id;
                brickCells[id].push_back({r, c});
                c++;
            }
        }
    }

    // Build adjacency among bricks
    vector<unordered_set<int>> adjSet(totalBricks);
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a = grid[i][j];
            if (a == -1) continue;
            for (int d = 0; d < 4; d++) {
                int ni = i + dr[d], nj = j + dc[d];
                if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
                int b = grid[ni][nj];
                if (b == -1 || b == a) continue;
                adjSet[a].insert(b);
                adjSet[b].insert(a);
            }
        }
    }

    vector<vector<int>> adj(totalBricks);
    for (int i = 0; i < totalBricks; i++)
        for (auto v : adjSet[i]) adj[i].push_back(v);

    // Identify start & destination bricks
    int src = -1, dst = -1;
    for (int i = 0; i < totalBricks; i++) {
        if (brickKind[i] == 'S') src = i;
        if (brickKind[i] == 'D') dst = i;
    }

    if (src == -1 || dst == -1) {
        cout << "-1\n";
        return 0;
    }

    // Dijkstra over brick nodes
    const int INF = 1e9;
    vector<int> best(totalBricks, INF);
    priority_queue<BrickNode> pq;
    best[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.cost != best[cur.idx]) continue;
        if (cur.idx == dst) break;

        for (int nb : adj[cur.idx]) {
            char typ = brickKind[nb];
            if (typ == 'R') continue;
            int add = (typ == 'G') ? 1 : 0;
            if (best[nb] > cur.cost + add) {
                best[nb] = cur.cost + add;
                pq.push({nb, best[nb]});
            }
        }
    }

    cout << (best[dst] == INF ? -1 : best[dst]) << "\n";
    return 0;
}
