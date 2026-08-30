//1D prefix sum
#include <bits/stdc++.h>
using namespace std;
vector<long long> pref(n + 1);

for(int i = 0; i < n; i++)
    pref[i + 1] = pref[i] + a[i];

// sum [l, r]
long long sum = pref[r + 1] - pref[l];
//2d prefix sum
vector<vector<long long>> pref(n + 1, vector<long long>(m + 1));

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        pref[i][j] = a[i-1][j-1]
                   + pref[i-1][j]
                   + pref[i][j-1]
                   - pref[i-1][j-1];
    }
}

// rectangle (x1,y1) -> (x2,y2)
long long sum =
    pref[x2][y2]
    - pref[x1-1][y2]
    - pref[x2][y1-1]
    + pref[x1-1][y1-1];