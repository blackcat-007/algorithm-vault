#include<bits/stdc++.h>
using namespace std;
int main() {
   
        int n;
        cin >> n;

        vector<int> a(n);
        int min=INT_MAX;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            min=std::min(min,abs(a[i]));
        }

      

        cout << min << '\n';
    

    return 0;
}