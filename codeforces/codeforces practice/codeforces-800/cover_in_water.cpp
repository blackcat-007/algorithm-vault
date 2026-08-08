#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n;
        cin >> s;

        int cnt = 0;
        int ans = 0;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                cnt++;

                if (cnt >= 3) {
                    found = true;
                    break;
                }
            } else {
                ans += cnt;
                cnt = 0;
            }
        }

        ans += cnt; // last segment

        if (found)
            cout << 2 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}