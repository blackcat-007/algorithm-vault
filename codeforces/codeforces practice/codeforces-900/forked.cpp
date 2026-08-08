#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long xK, yK;
        cin >> xK >> yK;

        long long xQ, yQ;
        cin >> xQ >> yQ;

        vector<pair<long long,long long>> moves = {
            {a,b}, {a,-b}, {-a,b}, {-a,-b},
            {b,a}, {b,-a}, {-b,a}, {-b,-a}
        };

        set<pair<long long,long long>> king;
        set<pair<long long,long long>> queen;

        for (const auto &move : moves) {
            long long dx = move.first;
            long long dy = move.second;
            king.insert({xK + dx, yK + dy});
            queen.insert({xQ + dx, yQ + dy});
        }

        int ans = 0;

        for (auto pos : king) {
            if (queen.count(pos))
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}