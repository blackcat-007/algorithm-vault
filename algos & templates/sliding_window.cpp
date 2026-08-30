//fixed size sliding window template
long long sum = 0, ans = 0;

for(int i = 0; i < n; i++) {
    sum += a[i];

    if(i >= k)
        sum -= a[i-k];

    if(i >= k-1)
        ans = max(ans, sum);
}
//variable size sliding window template
int l = 0;

for(int r = 0; r < n; r++) {

    // add a[r]

    while(/* window invalid */) {
        // remove a[l]
        l++;
    }

    // [l, r] is valid
}