#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        bool possible =
            // Multiply a by m
            (2 * b > c && (2 * b - c) % a == 0) ||

            // Multiply b by m
            ((a + c) % (2 * b) == 0) ||

            // Multiply c by m
            (2 * b > a && (2 * b - a) % c == 0);

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}