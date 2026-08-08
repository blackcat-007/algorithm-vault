#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x, n;
        cin >> x >> n;

        if (x % 2 == 0) {
            if (n % 4 == 0)
                cout << x;
            else if (n % 4 == 1)
                cout << x - n;
            else if (n % 4 == 2)
                cout << x + 1;
            else
                cout << x + n + 1;
        } else {
            if (n % 4 == 0)
                cout << x;
            else if (n % 4 == 1)
                cout << x + n;
            else if (n % 4 == 2)
                cout << x - 1;
            else
                cout << x - n - 1;
        }

        cout << '\n';
    }

    return 0;
}