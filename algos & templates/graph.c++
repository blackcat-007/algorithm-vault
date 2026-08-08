#include <bits/stdc++.h>
using namespace std;
int main() {
  int v;
  cin>>v;
    vector<vector<int>> adj(v);
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto j:adj[i]){
            cout<<j<<", ";
        }
        cout<<endl;
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); // For directed graph
       
    }
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto j:adj[i]){
            cout<<j<<", ";
        }
        cout<<endl;
    }
    

    return 0;
}