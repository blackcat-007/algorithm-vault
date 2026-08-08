#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> ans;

        if (x != 1) {
            for (int i = 0; i < n; i++) {
                ans.push_back(1);
            }
        }
        else {
            if (k == 1) {
                cout << "NO\n";
                continue;
            }

            if (k == 2) {
                if (n % 2 != 0) {
                    cout << "NO\n";
                    continue;
                }

                for (int i = 0; i < n / 2; i++) {
                    ans.push_back(2);
                }
            }
            else {
                // k >= 3, so 2 and 3 are available
                if (n % 2 == 0) {
                    for (int i = 0; i < n / 2; i++) {
                        ans.push_back(2);
                    }
                }
                else {
                    ans.push_back(3);
                    for (int i = 0; i < (n - 3) / 2; i++) {
                        ans.push_back(2);
                    }
                }
            }
        }

        cout << "YES\n";
        cout << ans.size() << "\n";

        for (int a : ans) {
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}