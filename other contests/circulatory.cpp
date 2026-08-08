#include <bits/stdc++.h>
using namespace std;

struct Node { int r, c, dist; };

int main() {
    int N;
    cin >> N;

    vector<string> rings(N);
    for(int i = 0; i < N; i++)
        cin >> rings[i];

    // PROPER FIX
    reverse(rings.begin(), rings.end());

    vector<vector<int>> maze(N);
    vector<vector<bool>> vis(N);

    for(int i = 0; i < N; i++){
        int len = rings[i].size();
        maze[i].resize(len);
        vis[i].resize(len, false);
        for(int j = 0; j < len; j++)
            maze[i][j] = rings[i][j] - '0';
    }

    queue<Node> q;

    // start from outer ring (which is now rings[0] after reversing)
    for(int c = 0; c < maze[0].size(); c++){
        if(maze[0][c] == 0){
            q.push({0, c, 1});
            vis[0][c] = true;
        }
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int r = cur.r, c = cur.c, dist = cur.dist;

        if(r == N - 1){ 
            cout << dist << endl;
            return 0;
        }

        int len = maze[r].size();

        // left
        int L = (c - 1 + len) % len;
        if(!vis[r][L] && maze[r][L] == 0){
            vis[r][L] = true;
            q.push({r, L, dist + 1});
        }

        // right
        int R = (c + 1) % len;
        if(!vis[r][R] && maze[r][R] == 0){
            vis[r][R] = true;
            q.push({r, R, dist + 1});
        }

        // inward
        if(r + 1 < N){
            int len_outer = maze[r].size();
            int len_inner = maze[r+1].size();

            int base = (c * len_inner) / len_outer;

            int child1 = base % len_inner;
            int child2 = (base + 1) % len_inner;

            if(!vis[r+1][child1] && maze[r+1][child1] == 0){
                vis[r+1][child1] = true;
                q.push({r+1, child1, dist + 1});
            }
            if(!vis[r+1][child2] && maze[r+1][child2] == 0){
                vis[r+1][child2] = true;
                q.push({r+1, child2, dist + 1});
            }
        }
    }

    cout << -1 << endl;
}
