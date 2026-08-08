#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        if(n % 2 != 0){//if n is odd, it is impossible to form the required pairs derived from the n=6a+4b => n=2(3a+2b) which is always even
            cout << -1 << "\n";
            continue;
        }

        long long mn = (n + 5) / 6; // ceil(n/6)
        long long mx = n / 4;

        if(mn <= mx)
            cout << mn << " " << mx << "\n";
        else
            cout << -1 << "\n";//consider if n=2
    }

    return 0;
}