
//prefix-suffix maximum 
vector<int> prefMax(n);
vector<int> suffMax(n);

prefMax[0] = a[0];

for(int i = 1; i < n; i++)
    prefMax[i] = max(prefMax[i - 1], a[i]);

suffMax[n - 1] = a[n - 1];

for(int i = n - 2; i >= 0; i--)
    suffMax[i] = max(suffMax[i + 1], a[i]);
//prefix-suffix minimum
vector<int> prefMin(n);
vector<int> suffMin(n);

prefMin[0] = a[0];

for(int i = 1; i < n; i++)
    prefMin[i] = min(prefMin[i - 1], a[i]);

suffMin[n - 1] = a[n - 1];

for(int i = n - 2; i >= 0; i--)
    suffMin[i] = min(suffMin[i + 1], a[i]);


//prefix suffix best answer
vector<long long> prefAns(n);
vector<long long> suffAns(n);

// calculate best answer in [0 ... i]
for(int i = 0; i < n; i++) {

    // update prefAns[i]
}

// calculate best answer in [i ... n-1]
for(int i = n - 1; i >= 0; i--) {

    // update suffAns[i]
}
for(int i = 0; i + 1 < n; i++) {

    // left = prefAns[i]
    // right = suffAns[i + 1]

    // combine them
}

//prefix suffix gcd
vector<long long> prefGcd(n + 1);
vector<long long> suffGcd(n + 1);

// prefix
for(int i = 0; i < n; i++)
    prefGcd[i + 1] = gcd(prefGcd[i], a[i]);

// suffix
for(int i = n - 1; i >= 0; i--)
    suffGcd[i] = gcd(suffGcd[i + 1], a[i]);

// GCD after removing a[i]
long long g = gcd(prefGcd[i], suffGcd[i + 1]);