#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool sorted = true;

        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }

        if (!sorted) {
            cout << 0 << '\n';
            continue;
        }

        long long mn = LLONG_MAX;

        for (int i = 0; i < n - 1; i++) {
            mn = min(mn, a[i + 1] - a[i]);
        }

        cout << (mn + 2) / 2 << '\n';
    }

    return 0;
}