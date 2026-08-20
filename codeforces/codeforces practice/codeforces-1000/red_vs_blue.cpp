#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        int groups = b + 1;

        // Minimum number of R's in each group
        int each = r / groups;

        // Number of groups that get one extra R
        int extra = r % groups;

        string ans = "";

        for (int i = 0; i < groups; i++) {

            int cnt = each;

            // Distribute the remaining R's
            if (extra > 0) {
                cnt++;
                extra--;
            }

            // Add R's of this group
            ans += string(cnt, 'R');

            // Add B between groups
            if (i < b) {
                ans += 'B';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}