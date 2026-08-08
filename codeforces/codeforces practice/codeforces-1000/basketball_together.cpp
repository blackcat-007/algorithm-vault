#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long D;
    cin >> n >> D;

    vector<long long> p(n);

    for (auto &x : p)
        cin >> x;

    sort(p.begin(), p.end());

    int left = 0;
    int right = n - 1;
    int ans = 0;

    while (left <= right) {
        // Strongest remaining player is p[right]
        long long strongest = p[right];

        // Minimum number of players needed
        long long need = D / strongest + 1;

        // We need 'need' players in this team.
        // Currently strongest player is already included.
        // So we need need - 1 additional players.
        if (right - left + 1 < need)
            break;

        ans++;

        // Use the weakest (need - 1) players
        left += need - 1;

        // Remove the strongest player
        right--;
    }

    cout << ans << '\n';

    return 0;
}