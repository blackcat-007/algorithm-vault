#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int neg = 0, pos = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == -1)
                neg++;
            else
                pos++;
        }

        int ans = 0;

        int diff = abs(neg - pos);

        if (neg > pos) {
            ans += (diff + 1) / 2;

            neg -= ans;
            pos += ans;
        }

        if (neg % 2 != 0) {
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}