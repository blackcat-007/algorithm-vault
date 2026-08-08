#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
       map<char, int> mp1, mp2;
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            mp1[a[i]]++;
            prefix[i + 1] = mp1.size();
        }

        for(int i = n - 1; i >= 0; i--) {
            mp2[a[i]]++;
            suffix[i] = mp2.size();
        }

        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans = max(ans, prefix[i] + suffix[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}