#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

// -------------------- DSU --------------------
struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int n=0) { init(n); }
    void init(int N) { 
	n = N; 
	parent.assign(n+1,0); 
	rankv.assign(n+1,0); 
	for(int i=1;i<=n;i++) 
	parent[i]=i;
	 }
    int find(int x){
	 return parent[x]==x?x:parent[x]=find(parent[x]);
	 }
    bool unite(int a,int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(rankv[a] < rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

// -------------------- Unweighted Graph (for BFS/DFS, etc.) --------------------
struct Graph {
    int n;
    bool directed;
    vector<vector<int>> adj;
    Graph(int n=0, bool directed=false){ 
	init(n,directed);
	 }
    void init(int N, bool dir=false){ 
	n=N; 
	directed=dir; 
	adj.assign(n+1,{});
	 }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }
    // Print adjacency
    void printAdj(){
        cout<<"Adjacency List:\n";
        for(int i=1;i<=n;i++){
            cout<<i<<": ";
            for(int v: adj[i]) cout<<v<<" ";
            cout<<"\n";
        }
    }
};

// -------------------- Weighted Graph --------------------
struct WeightedGraph {
    int n;
    bool directed;
    vector<vector<pair<int,ll>>> adj; // (to, weight)
    WeightedGraph(int n=0,bool directed=false){ 
	init(n,directed); 
	}
    void init(int N,bool dir=false){ 
	n=N; 
	directed=dir; 
	adj.assign(n+1,{}); 
	}
    void addEdge(int u,int v,ll w){
        adj[u].push_back({v,w});
        if(!directed) adj[v].push_back({u,w});
    }
};

// -------------------- BFS --------------------
vector<int> bfs_all(const Graph &G, int src){
    vector<int> vis(G.n+1,0),order;
    queue<int> q;
    q.push(src); vis[src]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(int v: G.adj[u]) 
	if(!vis[v]) { 
	vis[v]=1; q.push(v); 
	}
    }
    return order;
}
void print_bfs(const Graph &G,int src){
    auto ord = bfs_all(G,src);
    cout<<"BFS order from "<<src<<": ";
    for(int x:ord) cout<<x<<" ";
    cout<<"\n";
}

// -------------------- DFS --------------------
void dfs_rec(const Graph &G, int u, vector<int>& vis, vector<int>& order){
    vis[u]=1; 
    order.push_back(u);
    for(int v: G.adj[u]) 
	if(!vis[v]) 
	dfs_rec(G,v,vis,order);
}
vector<int> dfs_all(const Graph &G, int src){
    vector<int> vis(G.n+1,0), order;
    dfs_rec(G, src, vis, order);
    return order;
}
void print_dfs(const Graph &G, int src){
    auto ord = dfs_all(G, src);
    cout<<"DFS order from "<<src<<": ";
    for(int x: ord) cout<<x<<" ";
    cout<<"\n";
}

// -------------------- Connected Components --------------------
vector<vector<int>> connected_components(const Graph &G){
    vector<int> vis(G.n+1,0);
    vector<vector<int>> comps;
    for(int i=1;i<=G.n;i++){
        if(!vis[i]){
            vector<int> ord;
            dfs_rec(G,i,vis,ord);
            comps.push_back(ord);
        }
    }
    return comps;
}

// -------------------- Cycle Detection --------------------
// Undirected: DFS with parent
bool undirected_cycle_dfs(const Graph &G, int u, int parent, vector<int>& vis){
    vis[u] = 1;
    for(int v: G.adj[u]){
        if(!vis[v]){
            if(undirected_cycle_dfs(G,v,u,vis)) return true;
        } else if(v != parent) {
            return true;
        }
    }
    return false;
}
bool has_cycle_undirected(const Graph &G){
    vector<int> vis(G.n+1,0);
    for(int i=1;i<=G.n;i++) if(!vis[i]) if(undirected_cycle_dfs(G,i,-1,vis)) return true;
    return false;
}
// Directed: DFS with colors (0=white,1=gray,2=black)
bool directed_cycle_dfs(const Graph &G, int u, vector<int>& color){
    color[u]=1;
    for(int v: G.adj[u]){
        if(color[v]==0){
            if(directed_cycle_dfs(G,v,color)) return true;
        } 
	else if(color[v]==1) 
		return true; // back-edge
    }
    color[u]=2;
    return false;
}
bool has_cycle_directed(const Graph &G){
    vector<int> color(G.n+1,0);
    for(int i=1;i<=G.n;i++) 
	if(color[i]==0) 
		if(directed_cycle_dfs(G,i,color)) 
			return true;
    return false;
}

// -------------------- Topological Sort --------------------
// DFS-based topo
void topo_dfs(const Graph &G, int u, vector<int>& vis, vector<int>& out){
    vis[u]=1;
    for(int v: G.adj[u]) 
	if(!vis[v]) 
	topo_dfs(G,v,vis,out);
    out.push_back(u);
}
vector<int> topo_sort_dfs(const Graph &G){
    vector<int> vis(G.n+1,0), out;
    for(int i=1;i<=G.n;i++) if(!vis[i]) topo_dfs(G,i,vis,out);
    reverse(out.begin(), out.end());
    return out;
}
// Kahn's algorithm
vector<int> topo_kahn(const Graph &G){
    vector<int> indeg(G.n+1,0);
    for(int u=1;u<=G.n;u++){
        for(int v: G.adj[u]) indeg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=G.n;i++) if(indeg[i]==0) q.push(i);
    vector<int> order;
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(int v: G.adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    if((int)order.size() != G.n) return {}; // cycle -> no topo order
    return order;
}

// -------------------- Strongly Connected Components (Kosaraju) --------------------
vector<vector<int>> kosaraju_scc(const Graph &G){
    // 1) order by finish times
    vector<int> vis(G.n+1,0), order;
    for(int i=1;i<=G.n;i++) 
	if(!vis[i]) topo_dfs(G,i,vis,order);
    	reverse(order.begin(), order.end());
    // build reverse graph
    Graph GR(G.n, true);
    for(int u=1; u<=G.n; u++) 
	for(int v: G.adj[u]) 
		GR.addEdge(u,v); // addEdge will add only v->u? careful
    // We need reversed edges explicitly
    Graph GRrev(G.n, true);
    for(int u=1; u<=G.n; u++) 
	for(int v: G.adj[u]) GRrev.adj[v].push_back(u);

    vis.assign(G.n+1,0);
    vector<vector<int>> comps;
    for(int u: order){
        if(!vis[u]){
            vector<int> comp;
            // DFS on reversed graph
            stack<int> st; st.push(u); vis[u]=1;
            while(!st.empty()){
                int x=st.top(); st.pop();
                comp.push_back(x);
                for(int y: GRrev.adj[x]){
                    if(!vis[y]) { 
			vis[y]=1; st.push(y);
			 }
                }
            }
            comps.push_back(comp);
        }
    }
    return comps;
}

// -------------------- Dijkstra --------------------
vector<ll> dijkstra(const WeightedGraph &G, int src){
    vector<ll> dist(G.n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src]=0; pq.push({0,src});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]: G.adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// -------------------- Bellman-Ford --------------------
vector<ll> bellmanFord(int n, const vector<tuple<int,int,ll>>& edges, int src, bool &hasNegCycle){
    vector<ll> dist(n+1, INF);
    dist[src]=0;
    for(int i=1;i<=n-1;i++){
        for(auto &e: edges){
            int u,v; ll w; tie(u,v,w) = e;
            if(dist[u]!=INF && dist[u]+w < dist[v]) dist[v] = dist[u]+w;
        }
    }
    hasNegCycle = false;
    for(auto &e: edges){
        int u,v; ll w; tie(u,v,w) = e;
        if(dist[u]!=INF && dist[u]+w < dist[v]) { hasNegCycle = true; break; }
    }
    return dist;
}

// -------------------- Floyd-Warshall --------------------
vector<vector<ll>> floydWarshall(int n, const vector<tuple<int,int,ll>>& edges){
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(auto &e: edges){
        int u,v; ll w; tie(u,v,w)=e;
        dp[u][v] = min(dp[u][v], w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dp[i][k]!=INF && dp[k][j]!=INF)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    return dp;
}

// -------------------- Prim's MST --------------------
// returns MST total cost; if graph not connected returns -1 (or sum for connected component containing 1)
ll prims_mst(const WeightedGraph &G){
    int n = G.n;
    vector<char> used(n+1, false);
    vector<ll> minE(n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    minE[1]=0; pq.push({0,1});
    ll cost=0;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(used[u]) continue;
        used[u]=1;
        cost+=w;
        for(auto [v,wt]: G.adj[u]){
            if(!used[v] && wt < minE[v]){
                minE[v]=wt;
                pq.push({minE[v], v});
            }
        }
    }
    for(int i=1;i<=n;i++) if(!used[i]) return -1; // not connected
    return cost;
}

// -------------------- Kruskal's MST --------------------
ll kruskal_mst(int n, vector<tuple<int,int,ll>> edges){
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return get<2>(a) < get<2>(b);
    });
    DSU dsu(n);
    ll cost=0;
    int cnt=0;
    for(auto &e: edges){
        int u,v; ll w; tie(u,v,w)=e;
        if(dsu.unite(u,v)){
            cost += w;
            cnt++;
            if(cnt==n-1) break;
        }
    }
    if(cnt != n-1) return -1; // not connected
    return cost;
}

// -------------------- Bipartite Check --------------------
bool bipartite_bfs(const Graph &G){
    vector<int> color(G.n+1, -1);
    for(int i=1;i<=G.n;i++){
        if(color[i]!=-1) continue;
        queue<int> q; q.push(i); color[i]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: G.adj[u]){
                if(color[v]==-1){ color[v]=color[u]^1; q.push(v); }
                else if(color[v]==color[u]) return false;
            }
        }
    }
    return true;
}
bool bipartite_dfs_util(const Graph &G, int u, vector<int>& color){
    for(int v: G.adj[u]){
        if(color[v]==-1){
            color[v]=color[u]^1;
            if(!bipartite_dfs_util(G,v,color)) return false;
        } else if(color[v]==color[u]) return false;
    }
    return true;
}
bool bipartite_dfs(const Graph &G){
    vector<int> color(G.n+1, -1);
    for(int i=1;i<=G.n;i++){
        if(color[i]==-1){
            color[i]=0;
            if(!bipartite_dfs_util(G,i,color)) return false;
        }
    }
    return true;
}

// -------------------- Flood Fill (grid) --------------------
int flood_fill_count(vector<string>& grid, int sr, int sc, char target, char replacement){
    int R = grid.size();
    if(R==0) return 0;
    int C = grid[0].size();
    if(sr<0||sr>=R||sc<0||sc>=C) return 0;
    if(grid[sr][sc] != target) return 0;
    int cnt=0;
    queue<pair<int,int>> q;
    q.push({sr,sc});
    grid[sr][sc]=replacement;
    cnt++;
    int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nr=r+dr[k], nc=c+dc[k];
            if(nr>=0&&nr<R&&nc>=0&&nc<C && grid[nr][nc]==target){
                grid[nr][nc]=replacement;
                q.push({nr,nc});
                cnt++;
            }
        }
    }
    return cnt;
}

// -------------------- Helper print for distances --------------------
void print_distances_ll(const vector<ll> &dist){
    for(size_t i=1;i<dist.size();i++){
        if(dist[i]==INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}

// -------------------- Demonstration MAIN --------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    // Input format:
    // First line: n m directed(0/1) weighted(0/1)
    // Then m lines:
    // if weighted==0: u v
    // else: u v w
    // Nodes numbered 1..n

    int n, m;
    int directedFlag, weightedFlag;
    if(!(cin >> n >> m >> directedFlag >> weightedFlag)){
        cerr << "Expected input: n m directed(0/1) weighted(0/1)\n";
        return 0;
    }
    bool directed = (directedFlag != 0);
    bool weighted = (weightedFlag != 0);

    Graph G(n, directed);
    WeightedGraph WG(n, directed);
    vector<tuple<int,int,ll>> edgeList; // directed edges (u,v,w)
    for(int i=0;i<m;i++){
        int u,v; ll w=1;
        if(weighted) cin >> u >> v >> w;
        else cin >> u >> v;
        G.addEdge(u,v);
        if(weighted) WG.addEdge(u,v,w);
        else WG.addEdge(u,v,1);
        edgeList.emplace_back(u,v,w);
        if(!directed && weighted){
            // if undirected, ensure we also recorded reverse edge for edgeList? For Bellman-Ford/Floyd-W we typically add both
            edgeList.emplace_back(v,u,w);
        } else if(!directed && !weighted){
            edgeList.emplace_back(v,u,w);
        }
    }

    cout << "\n--- Graph summary ---\n";
    cout << "Nodes: " << n << ", Edges read: " << m << ", directed: " << directed << ", weighted: " << weighted << "\n";
    G.printAdj();
    cout << "\n";

    // BFS & DFS from node 1
    print_bfs(G, 1);
    print_dfs(G, 1);
    cout << "\n";

    // Connected Components
    auto comps = connected_components(G);
    cout << "Connected Components (" << comps.size() << "):\n";
    for(auto &c: comps){
        for(int x: c) cout<<x<<" ";
        cout<<"\n";
    }
    cout << "\n";

    // Cycle detection
    if(directed){
        cout << "Directed cycle present? " << (has_cycle_directed(G) ? "YES" : "NO") << "\n";
    } else {
        cout << "Undirected cycle present? " << (has_cycle_undirected(G) ? "YES" : "NO") << "\n";
    }

    // Topological sorts (only meaningful if directed)
    if(directed){
        auto topo1 = topo_sort_dfs(G);
        auto topo2 = topo_kahn(G);
        cout << "Topological (DFS-based): ";
        if(topo1.empty()) cout << "none\n"; else { for(int x:topo1) cout<<x<<" "; cout<<"\n"; }
        cout << "Topological (Kahn): ";
        if(topo2.empty()) cout << "none (cycle)\n"; else { for(int x:topo2) cout<<x<<" "; cout<<"\n"; }
    }

    // Kosaraju SCCs (for directed graphs)
    if(directed){
        auto sccs = kosaraju_scc(G);
        cout << "Strongly Connected Components (" << sccs.size() << "):\n";
        for(auto &c: sccs){
            for(int x: c) cout<<x<<" ";
            cout<<"\n";
        }
    }

    cout << "\n";

    // Dijkstra (requires non-negative weights)
    if(weighted){
        cout << "Dijkstra from 1:\n";
        auto distDij = dijkstra(WG, 1);
        print_distances_ll(distDij);
    } else {
        cout << "Skipping Dijkstra (unweighted - use BFS for shortest path on unit weights)\n";
    }

    // Bellman-Ford
    {
        bool negCycle=false;
        auto distBF = bellmanFord(n, edgeList, 1, negCycle);
        cout << "Bellman-Ford from 1: ";
        if(negCycle) cout << "(negative cycle detected) ";
        print_distances_ll(distBF);
    }

    // Floyd-Warshall
    {
        auto allpairs = floydWarshall(n, edgeList);
        cout << "Floyd-Warshall distance matrix (INF = unreachable):\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(allpairs[i][j]==INF) cout << "INF ";
                else cout << allpairs[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Prim's MST (weighted graph, undirected)
    if(!directed && weighted){
        ll primCost = prims_mst(WG);
        if(primCost<0) cout << "Prim's MST: Graph not connected\n";
        else cout << "Prim's MST cost: " << primCost << "\n";
    } else cout << "Skipping Prim's (requires weighted undirected graph)\n";

    // Kruskal's MST (undirected)
    if(!directed && weighted){
        // build undirected edge list (unique u<v entries)
        vector<tuple<int,int,ll>> undirectedEdges;
        // dedupe by ensuring u<v
        for(auto &e: edgeList){
            int u,v; ll w; tie(u,v,w)=e;
            if(u < v) undirectedEdges.emplace_back(u,v,w);
        }
        ll kruskalCost = kruskal_mst(n, undirectedEdges);
        if(kruskalCost<0) cout << "Kruskal's MST: Graph not connected\n";
        else cout << "Kruskal's MST cost: " << kruskalCost << "\n";
    } else cout << "Skipping Kruskal's (requires weighted undirected graph)\n";

    // Bipartite checks
    cout << "Bipartite (BFS)? " << (bipartite_bfs(G) ? "YES" : "NO") << "\n";
    cout << "Bipartite (DFS)? " << (bipartite_dfs(G) ? "YES" : "NO") << "\n";

    cout << "\n";

    // Flood fill demo (small manual grid demo)
    vector<string> grid = {
        ".....##",
        "...####",
        "...#..#",
        "......#"
    };
    cout << "Sample grid before flood-fill:\n";
    for(auto &r: grid) cout << r << "\n";
    int filled = flood_fill_count(grid, 0, 0, '.', 'o');
    cout << "Flood filled " << filled << " cells from (0,0). Grid after:\n";
    for(auto &r: grid) cout << r << "\n";

    cout << "\n--- End of toolkit run ---\n";
    return 0;
}
