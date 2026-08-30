long long gcd(long long a, long long b) {

    while(b) {
        a %= b;
        swap(a, b);
    }

    return a;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
//euclidean algorithm
long long extgcd(long long a, long long b,
                 long long &x, long long &y) {

    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;

    long long g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}
//fast power
long long binpow(long long a, long long b,
                 long long mod) {

    long long res = 1;

    while(b) {

        if(b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}
//mod inverse
long long modInverse(long long a, long long mod) {
    return binpow(a, mod - 2, mod);
}
//sieve of Eratosthenes
vector<bool> isPrime(n + 1, true);

isPrime[0] = isPrime[1] = false;

for(int i = 2; i * i <= n; i++) {

    if(isPrime[i]) {

        for(int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }
}

//smallest prime factor
vector<int> spf(n + 1);

for(int i = 0; i <= n; i++)
    spf[i] = i;

for(int i = 2; i * i <= n; i++) {

    if(spf[i] == i) {

        for(int j = i * i; j <= n; j += i) {

            if(spf[j] == j)
                spf[j] = i;
        }
    }
}
//factorization using smallest prime factor
vector<pair<int,int>> factorize(int x) {

    vector<pair<int,int>> res;

    while(x > 1) {

        int p = spf[x];
        int cnt = 0;

        while(x % p == 0) {
            x /= p;
            cnt++;
        }

        res.push_back({p, cnt});
    }

    return res;
}

//prime factorization using trial division
vector<long long> factorize(long long n) {

    vector<long long> factors;

    for(long long p = 2; p * p <= n; p++) {

        while(n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }

    if(n > 1)
        factors.push_back(n);

    return factors;
}

//number of divisors
long long divisorCount(long long n) {

    long long ans = 1;

    for(long long p = 2; p * p <= n; p++) {

        if(n % p == 0) {

            int cnt = 0;

            while(n % p == 0) {
                n /= p;
                cnt++;
            }

            ans *= (cnt + 1);
        }
    }

    if(n > 1)
        ans *= 2;

    return ans;
}

//euler's totient function
long long phi(long long n) {

    long long ans = n;

    for(long long p = 2; p * p <= n; p++) {

        if(n % p == 0) {

            while(n % p == 0)
                n /= p;

            ans -= ans / p;
        }
    }

    if(n > 1)
        ans -= ans / n;

    return ans;
}
//euler's totient function for all numbers from 1 to n
vector<int> phi(n + 1);

for(int i = 0; i <= n; i++)
    phi[i] = i;

for(int p = 2; p <= n; p++) {

    if(phi[p] == p) {

        for(int j = p; j <= n; j += p)
            phi[j] -= phi[j] / p;
    }
}

//moduler arithmetic
const long long MOD = 1e9 + 7;

x %= MOD;

x = (x + y) % MOD;

x = (x - y + MOD) % MOD;

x = x * y % MOD;

//nCr modulo
const long long MOD = 1e9 + 7;

vector<long long> fact(N + 1), invFact(N + 1);

fact[0] = 1;

for(int i = 1; i <= N; i++)
    fact[i] = fact[i-1] * i % MOD;

invFact[N] = binpow(fact[N], MOD - 2, MOD);

for(int i = N; i >= 1; i--)
    invFact[i-1] = invFact[i] * i % MOD;

long long C(int n, int r) {

    if(r < 0 || r > n)
        return 0;

    return fact[n]
         * invFact[r] % MOD
         * invFact[n-r] % MOD;
}

