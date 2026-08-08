#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> pref(n+1);

        for(int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            pref[i] = pref[i-1] + x;
        }

        long long total = pref[n];

        while(q--) {
            int l, r;
            long long k;
            cin >> l >> r >> k;

            long long old = pref[r] - pref[l-1];

            long long len = r - l + 1;

            long long newSum = total - old + len * k;

            if(newSum % 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}