#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<long long> copy=a;
        sort(a.begin(),a.end());
       reverse(a.begin(),a.end());
      map<long long, vector<long long>> mp;

for(int i = 0; i < n; i++){
    if(i % 2 == 0)
        mp[a[i]].push_back((i / 2) + 1);
    else
        mp[a[i]].push_back(-((i / 2) + 1));
}

map<long long, int> idx;
vector<long long> seq(n + 1);
long long time = 0;
for(int i = 1; i <= n; i++){
    long long x = copy[i-1];


seq[i] = mp[x].back();
mp[x].pop_back();

    time += abs(seq[0] - seq[i]) * 2 * x;
}
       cout<<time<<"\n";
       for(int i=0;i<=n;i++){
        cout<<seq[i]<<" ";
       }


       
    }
}