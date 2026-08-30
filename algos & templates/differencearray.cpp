vector<long long> diff(n + 1);

// add val to [l, r]
diff[l] += val;
diff[r + 1] -= val;

// reconstruct
for(int i = 1; i <= n; i++)
    diff[i] += diff[i - 1];