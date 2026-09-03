#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char mx = s[0];
    int mxPos = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] < mx) {
            cout << "YES\n";
            cout << mxPos + 1 << " " << i + 1 << "\n";
            return 0;
        }

        if (s[i] > mx) {
            mx = s[i];
            mxPos = i;
        }
    }

    cout << "NO\n";

    return 0;
}