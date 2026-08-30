vector<long long> suff(n + 1, 0);

for(int i = n - 1; i >= 0; i--)
    suff[i] = suff[i + 1] + a[i];

// sum [l, r]
long long sum = suff[l] - suff[r + 1];

//suffix maximum 
vector<int> suffMax(n);

suffMax[n - 1] = a[n - 1];

for(int i = n - 2; i >= 0; i--)
    suffMax[i] = max(a[i], suffMax[i + 1]);

//suffix minimum 
vector<int> suffMin(n);

suffMin[n - 1] = a[n - 1];

for(int i = n - 2; i >= 0; i--)
    suffMin[i] = min(a[i], suffMin[i + 1]);

//suffix gcd 
vector<long long> suffGcd(n + 1, 0);

for(int i = n - 1; i >= 0; i--)
    suffGcd[i] = gcd(suffGcd[i + 1], a[i]);
//suffix frequency 
vector<array<int,26>> suff(n + 1);

for(int i = n - 1; i >= 0; i--) {

    suff[i] = suff[i + 1];

    suff[i][s[i] - 'a']++;
}

//suffix xor
vector<int> suffXor(n + 1);

for(int i = n - 1; i >= 0; i--)
    suffXor[i] = suffXor[i + 1] ^ a[i];

//suffix one
vector<int> suffOne(n + 1);

for(int i = n - 1; i >= 0; i--)
    suffOne[i] = suffOne[i + 1] + (a[i] == 1);