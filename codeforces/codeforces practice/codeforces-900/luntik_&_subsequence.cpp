# include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int zero=0;
        int ones=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) zero++;
            else if(a[i]==1) ones++;
        }
        cout<<(long long)pow(2,zero) * ones<<endl;

    }
    return 0;
}