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

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> prefix(n), suffix(n);

        // store count of 2s in prefix
        prefix[0] = (a[0] == 2);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (a[i] == 2);
        }

        // store count of 2s in suffix
        suffix[n - 1] = (a[n - 1] == 2);

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (a[i] == 2);
        }

        int ans = -1;

        for (int k = 0; k < n - 1; k++) {
            if (prefix[k] == suffix[k + 1]) {
                ans = k + 1; // k is 0-indexed, answer is 1-indexed
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}