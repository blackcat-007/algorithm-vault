#include <bits/stdc++.h>
int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n,k;
        std::cin >> n >> k;
        bool present=false;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if(a[i] == k) {
             present=true;
            }
        }
        if(present) {
            std::cout << "YES" << '\n';
            continue;
        }
        else {
            std::cout << "NO" << '\n';
        }
    }

    return 0;
}
