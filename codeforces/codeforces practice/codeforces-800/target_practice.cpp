#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
      

        vector<vector<char>> mat(10, vector<char>(10));
        vector<vector<int>> ref(10, vector<int>(10, 0));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int layer = min({i, j, 9 - i, 9 - j});// Calculate the layer based on the minimum distance to the edges
                ref[i][j]=layer+1;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++) {
            
            for (int j = 0; j < 10; j++) {
                if(mat[i][j] == 'X') {
                    ans += ref[i][j];
                }
            }
           
        }
  
        cout << ans << '\n';
    }

    return 0;
}