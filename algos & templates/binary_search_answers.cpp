long long lo = low, hi = high;

while(lo < hi) {

    long long mid = lo + (hi - lo) / 2;

    if(check(mid))
        hi = mid;
    else
        lo = mid + 1;
}

cout << lo;
//for maximum valid
long long lo = low, hi = high;

while(lo < hi) {

    long long mid =
        lo + (hi - lo + 1) / 2;

    if(check(mid))
        lo = mid;
    else
        hi = mid - 1;
}