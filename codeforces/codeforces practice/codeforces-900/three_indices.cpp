#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
       bool found=false;
        int pi,pj,pk;
        for(int i=0;i<n;i++){
             int count=1;
            for(int j=i+1;j<n;j++){
                if(count==1 && a[i]<a[j]){
                    count++;
                    pi=i;
                    pj=j;
                }
                else if(count==2 && a[pj]>a[j]){
                    count++;
                    pk=j;
                }
                
            }
            if(count==3){
                found=true;
                cout<<"YES"<<endl;
                cout<<pi+1<<" "<<pj+1<<" "<<pk+1<<endl;
                break;
            }
        }
        if(!found){
            cout<<"NO"<<endl;
        }
    }
}