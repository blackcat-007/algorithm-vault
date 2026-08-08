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

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = a[n-1] - a[0];

        for (int i = 0; i < n; i++) {
            ans = max(ans, a[i] - a[0]);
            ans = max(ans, a[n-1] - a[i]);

            if (i + 1 < n)
                ans = max(ans, a[i] - a[i+1]);
        }

        cout << ans << "\n";
    }

    return 0;
}