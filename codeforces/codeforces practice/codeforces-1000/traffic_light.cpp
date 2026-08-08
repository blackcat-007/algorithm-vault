#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        string t = s+s;
        int m = t.size();

int nextGreen = -1;
int ans = 0;

for (int i = m - 1; i >= 0; i--) {
    if (t[i] == 'g')
        nextGreen = i;

    if (i < n && t[i] == c)
        ans = max(ans, nextGreen - i);
}

cout << ans << '\n';

    }
}