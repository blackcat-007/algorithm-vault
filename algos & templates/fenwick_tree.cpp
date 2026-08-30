struct Fenwick {

    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int idx, long long val) {

        for(; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long sum(int idx) {

        long long ans = 0;

        for(; idx > 0; idx -= idx & -idx)
            ans += bit[idx];

        return ans;
    }

    long long rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

/*
idx += idx & -idx   → update
idx -= idx & -idx   → query
*/