#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool aliceTurn = true;

        while (true) {
            bool found = false;

            for (int i = 0; i + 1 < s.size(); i++) {

                // We found a valid pair
                if (s[i] != s[i + 1]) {

                    // Remove both characters
                    s.erase(i, 2);

                    // Change turn
                    aliceTurn = !aliceTurn;

                    found = true;
                    break;
                }
            }

            // No valid move
            if (!found)
                break;
        }

        // If it is Alice's turn, Alice couldn't move
        // Therefore Bob made the last move.
        if (aliceTurn)
            cout << "NET\n";
        else
            cout << "DA\n";
    }

    return 0;
}