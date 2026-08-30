int l = 0, r = n - 1;

while(l < r) {

    long long sum = a[l] + a[r];

    if(sum == target) {
        // found
        l++;
        r--;
    }
    else if(sum < target)
        l++;
    else
        r--;
}