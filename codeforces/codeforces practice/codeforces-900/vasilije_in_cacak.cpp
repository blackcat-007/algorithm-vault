#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,k,s;
        cin >> n >> k >> s;
        long long minsum=k*(k+1)/2;
        long long maxsum=k*(2*n-k+1)/2;
        if(s>=minsum &&  s<=maxsum){
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}