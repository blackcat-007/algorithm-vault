#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long d;
        cin >> d;

        long long a = d + 1;

        // Find first prime >= d + 1
        while (!isPrime(a)) {
            a++;
        }

        long long b = a + d;

        // Find first prime >= a + d
        while (!isPrime(b)) {
            b++;
        }

        cout << a * b << '\n';
    }

    return 0;
}