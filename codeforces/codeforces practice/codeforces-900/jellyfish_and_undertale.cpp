#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    long long A,B,n;
    cin>>A>>B>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    
    for(int i=0;i<n;i++){
       B+=min(a[i],A-1);
    }
    cout<<B<<endl;
}
return 0;
}