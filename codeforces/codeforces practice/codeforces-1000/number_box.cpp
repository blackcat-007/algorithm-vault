#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>> a(n+1,vector<long long>(m+1));
        int negcount=0;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]<0){
                    negcount++;
                }
            }
           
        }
        if(negcount%2==0){
            long long sum=0;
            for(long long i=1;i<=n;i++){
                for(long long j=1;j<=m;j++){
                    sum+=abs(a[i][j]);
                }
            }
            cout<<sum<<"\n";
        }
        else{
            long long sum=0;
            long long minval=INT_MAX;
            for(long long i=1;i<=n;i++){
                for(long long j=1;j<=m;j++){
                    sum+=abs(a[i][j]);
                    minval=min(minval,abs(a[i][j]));
                }
            }
            cout<<sum-2*minval<<"\n";
        }
    }
}