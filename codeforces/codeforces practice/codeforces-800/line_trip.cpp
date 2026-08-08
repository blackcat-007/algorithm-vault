#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxdiff = INT_MIN;

        // First element difference with 0
        maxdiff = max(maxdiff, a[0] - 0);

        // Consecutive differences
        for (int i = 1; i < n; i++) {
            maxdiff = max(maxdiff, a[i] - a[i - 1]);
        }

        // Last difference with x, doubled
        maxdiff = max(maxdiff, 2 * (x - a[n - 1]));

        cout << maxdiff << '\n';
    }

    return 0;
}