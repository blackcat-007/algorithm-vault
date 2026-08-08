#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int count = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == 0) {
                count++;
            } 
            else {
                maxi = max(maxi, count);
                count = 0;
            }
        }

        maxi = max(maxi, count);

        cout << maxi << endl;
    }

    return 0;
}