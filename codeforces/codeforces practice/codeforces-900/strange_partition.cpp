#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        long long sum=0;
        long long partsum=0;
        //vector<long long>a(n);
        for(long long i=0;i<n;i++){
            long long a;
            cin>>a;
            sum+=a;
           if(a%x!=0){
               partsum+=(a/x)+1;
           }
           else{
               partsum+=a/x;
           }
        }
        if(sum%x!=0){
            cout<<sum/x+1<<" "<<partsum<<endl;
        }
        else
            cout<<sum/x<<" "<<partsum<<endl;
       
           
    }
}