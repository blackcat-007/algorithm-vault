#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n ;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int count=0;
        bool flag=false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] != 0 && flag == false) {
                count++;
                flag = true;
            } else if (a[i] == 0) {
                flag= false;
            }
        }

        
        cout << min(count,2) << "\n";
    }

    return 0;
}