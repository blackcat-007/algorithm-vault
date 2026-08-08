#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) {
            cout << "NO\n";
            continue;
        }

        sort(a.rbegin(), a.rend());

        vector<int> ans;

        int l = 0, r = n - 1;

        while (l <= r) {
            ans.push_back(a[l]);
            l++;

            if (l <= r) {
                ans.push_back(a[r]);
                r--;
            }
        }

        cout << "YES\n";

        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}