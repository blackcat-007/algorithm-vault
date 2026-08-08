#include <bits/stdc++.h>
using namespace std;

void dfs(const string &cur, const string &target, unordered_map<string, vector<string>> &links,
         unordered_set<string> &restricted, unordered_set<string> &visited, bool &found) {
    if (cur == target) {
        found = true;
        return;
    }
    visited.insert(cur);
    for (auto &nxt : links[cur]) {
        if (found) return;
        if (visited.count(nxt)) continue;
        if (restricted.count(nxt)) continue;
        dfs(nxt, target, links, restricted, visited, found);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    unordered_map<string, vector<string>> network;
    string line;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss(line);
        vector<string> parts;
        string temp;
        while (ss >> temp) parts.push_back(temp);
        for (int j = 1; j < (int)parts.size(); j++) {
            network[parts[0]].push_back(parts[j]);
            network[parts[j]].push_back(parts[0]);
        }
    }

    int Q;
    cin >> Q;
    cin.ignore();

    vector<string> queries(Q);
    for (int i = 0; i < Q; i++) getline(cin, queries[i]);

    int R;
    cin >> R;
    cin.ignore();

    unordered_map<string, unordered_set<string>> limit;
    for (int i = 0; i < R; i++) {
        getline(cin, line);
        stringstream ss(line);
        string src, stop;
        ss >> src;
        while (ss >> stop) limit[src].insert(stop);
    }

    // process each query
    for (auto &query : queries) {
        stringstream ss(query);
        string a, b, cmd;
        ss >> a;

        if (query.find("to") != string::npos) {
            ss >> cmd >> b; // "a to b"
            unordered_set<string> seen;
            bool canReach = false;
            unordered_set<string> stopSet = limit[a];
            dfs(a, b, network, stopSet, seen, canReach);
            cout << (canReach ? "yes" : "no") << "\n";
        } 
        else if (query.find("connects") != string::npos) {
            ss >> cmd >> b; // "a connects b"
            network[a].push_back(b);
            network[b].push_back(a);
        } 
        else if (query.find("disconnects") != string::npos) {
            ss >> cmd >> b; // "a disconnects b"
            auto &va = network[a];
            va.erase(remove(va.begin(), va.end(), b), va.end());
            auto &vb = network[b];
            vb.erase(remove(vb.begin(), vb.end(), a), vb.end());
        }
    }

    return 0;
}
