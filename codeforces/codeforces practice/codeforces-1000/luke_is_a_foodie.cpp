#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);
        for (auto &i : a)
            cin >> i;

        // Choose the smallest possible upper bound initially
        long long v = a[0] + x;

        int changes = 0;

        for (int i = 1; i < n; i++) {

            // If current v can eat this pile
            if (abs(v - a[i]) <= x) {
                continue;
            }

            // Otherwise, change v
            changes++;

            // Choose a new v for the current pile
            // We want v to be as close as possible
            // to the previous v while satisfying current pile
            if (v < a[i] - x) {
                v = a[i] - x;
            } 
            else if (v > a[i] + x) {
                v = a[i] + x;
            }
        }

        cout << changes << '\n';
    }

    return 0;
}