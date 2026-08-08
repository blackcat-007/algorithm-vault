#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> freq(26);

        for(char c : s)
            freq[c-'a']++;

        int odd = 0;

        for(int x : freq)
            if(x % 2)
                odd++;

        int need = k;

        // remove odd frequency characters first
        int removedFromOdd = min(need, odd);

        odd -= removedFromOdd;
        need -= removedFromOdd;


        // remaining deletions are from even groups
        // if we remove odd number of chars from even groups,
        // it will create one odd frequency

        if(need % 2 == 1)
            odd++;


        int len = n-k;

        if(len % 2 == 0)
        {
            cout << (odd == 0 ? "YES" : "NO") << '\n';
        }
        else
        {
            cout << (odd == 1 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}