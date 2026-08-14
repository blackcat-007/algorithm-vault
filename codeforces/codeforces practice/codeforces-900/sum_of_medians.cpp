#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n * k);

        for (long long i = 0; i < n * k; i++)
            cin >> a[i];

        reverse(a.begin(), a.end());

        long long mid = (n + 1) / 2;
        long long interval = n - mid + 1;

        long long steps = interval - 1;   // FIX

        long long sum = 0;

        for (long long i = 0; i < k; i++) {
            sum += a[steps];
            steps += interval;            // FIX
        }

        cout << sum << endl;
    }
}