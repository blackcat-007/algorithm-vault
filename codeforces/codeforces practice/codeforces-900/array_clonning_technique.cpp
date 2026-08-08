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

        vector<long long> a(n);

        map<long long, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        // Find the maximum frequency
        int cnt = 0;

        for (auto &[value, frequency] : freq) {
            cnt = max(cnt, frequency);
        }

        int ans = 0;

        // Keep cloning and swapping
        while (cnt < n) {
            // One clone operation
            ans++;

            // Number of positions we still need to fill
            int need = n - cnt;

            // We can fill at most cnt positions
            int take = min(cnt, need);

            // Each filled position requires one swap
            ans += take;

            // Increase number of correct elements
            cnt += take;
        }

        cout << ans << '\n';
    }

    return 0;
}