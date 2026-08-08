#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long sumSecond = 0;
        int minFirst = INT_MAX;
        int minSecond = INT_MAX;

        while (n--) {
            int m;
            cin >> m;

            vector<int> a(m);
            for (int i = 0; i < m; i++)
                cin >> a[i];

            sort(a.begin(), a.end());

            minFirst = min(minFirst, a[0]);
            minSecond = min(minSecond, a[1]);
            sumSecond += a[1];
        }

        cout << sumSecond - minSecond + minFirst << '\n';
    }

    return 0;
}