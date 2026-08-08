#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n);
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        if (n == 2) {
            cout << "Yes\n";
            continue;
        }
 
        bool allSame = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                allSame = false;
                break;
            }
        }
 
        if (allSame) {
            cout << "Yes\n";
            continue;
        }
 
        sort(a.begin(), a.end());
 
        map<int, int> mp;
 
        for (int x : a) {
            mp[x]++;
        }
 
        if (mp.size() != 2) {
            cout << "No\n";
            continue;
        }
 
        auto it = mp.begin();
        int f1 = it->second;
        ++it;
        int f2 = it->second;
 
        if (n % 2 == 0) {
            if (f1 == f2)
                cout << "Yes\n";
            else
                cout << "No\n";
        } else {
            if (abs(f1 - f2) == 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
 
    return 0;
}