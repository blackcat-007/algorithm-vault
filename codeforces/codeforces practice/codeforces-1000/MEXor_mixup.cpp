#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long mex, xor1;
        cin >> mex >> xor1;

        long long n = mex - 1;
        long long findxor;

        if(n % 4 == 0)
            findxor = n;
        else if(n % 4 == 1)
            findxor = 1;
        else if(n % 4 == 2)
            findxor = n + 1;
        else
            findxor = 0;

        if(findxor == xor1)
            cout << mex << "\n";
        else if((findxor ^ xor1) == mex)
            cout << mex + 2 << "\n";
        else
            cout << mex + 1 << "\n";
    }
}