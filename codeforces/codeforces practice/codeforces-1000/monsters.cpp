#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<pair<int,int>> b(n);
        for(int i=0;i<n;i++){
            b[i]={i,a[i]%k};
        }
        sort(b.begin(),b.end(),[](pair<int,int> x,pair<int,int> y){
            return x.second>y.second;
        });
        for(int i=0;i<n;i++){   
            cout<<b[i].first+1<<" ";
        }
        cout<<endl;
    }

}