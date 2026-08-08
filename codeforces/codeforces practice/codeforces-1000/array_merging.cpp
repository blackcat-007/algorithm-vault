#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        map<int, int> mp1, mp2;

        // Longest consecutive run in a
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            mp1[a[i]] = max(mp1[a[i]], j - i);
            i = j;
        }

        // Longest consecutive run in b
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && b[j] == b[i]) j++;
            mp2[b[i]] = max(mp2[b[i]], j - i);
            i = j;
        }

        int ans = 0;

        for (auto &x : mp1)
            ans = max(ans, x.second + mp2[x.first]);

        for (auto &x : mp2)
            ans = max(ans, x.second + mp1[x.first]);

        cout << ans << '\n';
    }

    return 0;
}