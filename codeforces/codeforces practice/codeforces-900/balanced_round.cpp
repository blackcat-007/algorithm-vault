#include<bits/stdc++.h>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int startindex=0;
        int lastindex=0;
        int maxi=0;
        for(int i=1;i<n;i++){
           if(a[i]-a[i-1]>k){
             lastindex=i-1;
             maxi=max(maxi,lastindex-startindex+1);
             startindex=i;
             

           }
           lastindex=i;
        }
        maxi=max(maxi,lastindex-startindex+1);
        cout<<n-maxi<<endl;
    }
}
