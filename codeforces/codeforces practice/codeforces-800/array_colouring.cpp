#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int total = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            total += x;
        }

        if (total % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}