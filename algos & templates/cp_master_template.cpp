#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 4e18;
const ll MOD = 1e9 + 7;

ll gcdll(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll binpow(ll a, ll b, ll mod = MOD) {

    ll res = 1;

    while(b) {

        if(b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

void solve() {

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}