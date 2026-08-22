#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long w, h;
        cin >> w >> h;

        long long ans = 0;

        // Bottom horizontal side
        int k;
        cin >> k;

        long long first, last;
        cin >> first;

        long long x;
        for (int i = 1; i < k; i++) {
            cin >> x;
        }
        last = x;

        ans = max(ans, (last - first) * h);

        // Top horizontal side
        cin >> k;

        cin >> first;
        for (int i = 1; i < k; i++) {
            cin >> x;
        }
        last = x;

        ans = max(ans, (last - first) * h);

        // Left vertical side
        cin >> k;

        cin >> first;
        for (int i = 1; i < k; i++) {
            cin >> x;
        }
        last = x;

        ans = max(ans, (last - first) * w);

        // Right vertical side
        cin >> k;

        cin >> first;
        for (int i = 1; i < k; i++) {
            cin >> x;
        }
        last = x;

        ans = max(ans, (last - first) * w);

        cout << ans << '\n';
    }

    return 0;
}