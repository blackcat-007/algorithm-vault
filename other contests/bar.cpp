#include <bits/stdc++.h>
using namespace std;

struct Bar {
    double x1, y1, x2, y2;
};

vector<Bar> bars;
set<pair<int,int>> results; 
set<string> visited; 

bool onSegment(double x, double y, const Bar &b) {
    double minx = min(b.x1, b.x2) - 1e-9;
    double maxx = max(b.x1, b.x2) + 1e-9;
    double miny = min(b.y1, b.y2) - 1e-9;
    double maxy = max(b.y1, b.y2) + 1e-9;
    return (x >= minx && x <= maxx && y >= miny && y <= maxy);
}

// Gravity: find the closest bar below
bool gravityFall(double x, double y, double &nx, double &ny, int &barIndex) {
    double bestY = -1;
    barIndex = -1;

    for (int i = 0; i < bars.size(); i++) {
        Bar b = bars[i];
        // Solve intersection with vertical line x = constant
        if (b.x1 == b.x2) continue; // avoid vertical

        double t = (x - b.x1) / (b.x2 - b.x1);
        if (t < -1e-9 || t > 1+1e-9) continue;

        double yy = b.y1 + t * (b.y2 - b.y1);

        if (yy < y - 1e-9) {
            if (yy > bestY) {
                bestY = yy;
                barIndex = i;
            }
        }
    }

    if (barIndex == -1) return false;
    nx = x;
    ny = bestY;
    return true;
}

// Determine if bar is ascending or descending left→right
bool isAscending(const Bar &b) {
    return b.y2 > b.y1;
}

// Get lower endpoint of bar
void getLowerPoint(const Bar &b, double &x, double &y) {
    if (b.y1 < b.y2) x = b.x1, y = b.y1;
    else x = b.x2, y = b.y2;
}

// Get upper endpoint of bar
void getUpperPoint(const Bar &b, double &x, double &y) {
    if (b.y1 > b.y2) x = b.x1, y = b.y1;
    else x = b.x2, y = b.y2;
}

bool isCrossBar(int idx) {
    // Cross bar means two bars share the same midpoint
    double mx = (bars[idx].x1 + bars[idx].x2) / 2.0;
    double my = (bars[idx].y1 + bars[idx].y2) / 2.0;

    int count = 0;
    for (auto &b : bars) {
        double mmx = (b.x1 + b.x2) / 2.0;
        double mmy = (b.y1 + b.y2) / 2.0;
        if (fabs(mmx - mx) < 1e-9 && fabs(mmy - my) < 1e-9) count++;
    }
    return count == 2;
}

void dfs(double x, double y) {
    string key = to_string((int)x) + "|" + to_string((int)y);
    if (visited.count(key)) return;
    visited.insert(key);

    // If already at ground
    if (y <= 0) {
        results.insert({(int)round(x), 0});
        return;
    }

    double nx, ny;
    int barIndex;

    // Gravity fall
    if (!gravityFall(x, y, nx, ny, barIndex)) {
        // reaches ground at x
        results.insert({(int)round(x), 0});
        return;
    }

    // Now ball is ON barIndex at (nx, ny)
    Bar b = bars[barIndex];

    // follow natural slope down
    double lx, ly;
    getLowerPoint(b, lx, ly);

    if (fabs(nx - lx) < 1e-9 && fabs(ny - ly) < 1e-9) {
        // Already at lower end → gravity again
        dfs(nx, ny);
    } else {
        // slide downward normally
        dfs(lx, ly);
    }

    // ---- TILT OPTIONS ----
    // Cross-bar tilt rotates around intersection (keeps intersection fixed)
    // Single-bar tilt rotates around midpoint
    double cx, cy;

    if (isCrossBar(barIndex)) {
        cx = (b.x1 + b.x2) / 2.0;
        cy = (b.y1 + b.y2) / 2.0;
    } else {
        cx = (b.x1 + b.x2) / 2.0;
        cy = (b.y1 + b.y2) / 2.0;
    }

    // Tilt 90° clockwise (x,y) -> (y, -x)
    {
        double tx = cx + (ny - cy);
        double ty = cy - (nx - cx);
        dfs(tx, ty);
    }

    // Tilt 90° anticlockwise (x,y)->(-y,x)
    {
        double tx = cx - (ny - cy);
        double ty = cy + (nx - cx);
        dfs(tx, ty);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    bars.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bars[i].x1 >> bars[i].y1 >> bars[i].x2 >> bars[i].y2;
    }

    double bx, by;
    cin >> bx >> by;

    dfs(bx, by);

    vector<pair<int,int>> out(results.begin(), results.end());
    sort(out.begin(), out.end());

    for (auto &p : out) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
