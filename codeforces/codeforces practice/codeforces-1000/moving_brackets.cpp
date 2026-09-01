#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        stack<char> st;
        int ans = 0;

        for (char c : s) {

            if (c == '(') {
                st.push(c);
            }
            else {
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    // Unmatched ')'
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}