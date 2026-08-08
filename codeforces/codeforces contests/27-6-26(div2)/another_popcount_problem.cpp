#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long div = n / k;
        long long rem = n % k;

        long long ans = 0;

        if (rem == 0) {
            ans = k * __builtin_popcountll(div);
        } 
        else {
            ans = rem * __builtin_popcountll(div + 1) 
                + (k - rem) * __builtin_popcountll(div);
        }

        cout << ans << "\n";
    }

    return 0;
}