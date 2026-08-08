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

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] == 1)
                a[i] = 2;
        }

        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] % a[i] == 0)
                a[i + 1]++;
        }

        for (auto x : a)
            cout << x << " ";

        cout << "\n";
    }
}