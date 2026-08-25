#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int ans = a.size() + b.size();

        for (int i = 0; i < a.size(); i++) {
            for (int j = i; j < a.size(); j++) {

                string sub = a.substr(i, j - i + 1);

                size_t pos = b.find(sub);

                if (pos != string::npos) {

                    int operationsA =
                        i + (a.size() - j - 1);

                    int operationsB =
                        pos + (b.size() - pos - sub.size());

                    ans = min(ans, operationsA + operationsB);
                }
            }
        }

        cout << ans << '\n';
    }
}