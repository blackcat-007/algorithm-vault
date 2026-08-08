#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        string x, s;
        cin >> x;
        cin >> s;
 
        int ans = -1;
 
        for (int ops = 0; ops <= 6; ops++) {
            if (x.find(s) != string::npos) {
                ans = ops;
                break;
            }
 
            x += x;
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}