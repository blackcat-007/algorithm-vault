#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;

        long long minimumSum = b * k;
        long long maximumSum = b * k + n * (k - 1);

        // Impossible cases
        if (s < minimumSum || s > maximumSum) {
            cout << -1 << '\n';
            continue;
        }

        vector<long long> a(n, 0);

        // Give all beauty to the first element
        a[0] = b * k;

        // Extra amount that needs to be distributed
        long long remaining = s - b * k;

        // We can add at most k-1 without increasing beauty
        long long add = min(remaining, k - 1);
        a[0] += add;
        remaining -= add;

        // Distribute remaining amount
        // Each element must be <= k-1
        for (int i = 1; i < n && remaining > 0; i++) {
            add = min(remaining, k - 1);
            a[i] = add;
            remaining -= add;
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << '\n';
    }

    return 0;
}