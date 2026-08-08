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

        if (is_sorted(a.begin(), a.end())) {
            cout << "YES\n";
            continue;
        }

        bool firstCorrect = (a[0] == 1);
        bool hasPeak = false;

        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                hasPeak = true;
                break;
            }
        }

        if (firstCorrect && hasPeak)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}