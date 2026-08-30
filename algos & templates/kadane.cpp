long long cur = 0;
long long ans = LLONG_MIN;

for(long long x : a) {

    cur = max(x, cur + x);

    ans = max(ans, cur);
}