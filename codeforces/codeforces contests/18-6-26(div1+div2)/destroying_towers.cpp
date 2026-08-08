#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
        }
        for(int i=n;i>=0;i--){
           for(int j=i-1;j>=0;j--){
               if(a[j]<a[i]){
                  a[i]=a[j];
               }
           }
        }
        int sum=0;
        for(int i = 0; i < n; i++) {
            sum+=a[i];
        }
        cout << sum << "\n";
    }

    return 0;
}