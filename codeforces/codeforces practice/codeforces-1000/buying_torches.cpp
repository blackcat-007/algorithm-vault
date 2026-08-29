#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main(){
    int t;
    cin>>t;
    while(t--){
         long long x,y,n;
        cin>>x>>y>>n;
        long long stickTrades = (n * (y + 1) - 1 + (x - 2)) / (x - 1);
        cout<<(stickTrades + n)<<endl;

    }
}