#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long up = d - b;

        if (up < 0) {
            cout << -1 << "\n";
            continue;
        }

        long long afterDiagonal = a + up;

        if (afterDiagonal < c) {
            cout << -1 << "\n";
            continue;
        }

        long long left = afterDiagonal - c;

        cout << up + left << "\n";
    }

    return 0;
}