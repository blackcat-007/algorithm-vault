#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b,c;
        sort(a.begin(), a.end());
        b.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            if(a[i]==b[0]){
                b.push_back(a[i]);
            }
            else {
                c.push_back(a[i]);
            }

        }
        if(c.size()==0) {
            cout << -1<< '\n';
            continue;
        }
        cout << b.size() << ' ';
        cout<<c.size() << '\n';
        
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < c.size(); i++) {
            cout << c[i] << ' ';
        }
        cout << '\n';

    }

    return 0;
}
