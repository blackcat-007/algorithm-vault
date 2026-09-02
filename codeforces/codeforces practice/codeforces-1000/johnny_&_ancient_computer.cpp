#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        int ca = 0, cb = 0;

        // Remove all factors of 2 from a
        while (a % 2 == 0) {
            a /= 2;
            ca++;
        }

        // Remove all factors of 2 from b
        while (b % 2 == 0) {
            b /= 2;
            cb++;
        }

        // Odd parts must be equal
        if (a != b) {
            cout << -1 << '\n';
            continue;
        }

        int diff = abs(ca - cb);

        cout << (diff + 2) / 3 << '\n';
    }

    return 0;
}