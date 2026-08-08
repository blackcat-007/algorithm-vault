#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (s.front() != s.back()) {
            // Make the last character equal to the first.
            // (Changing the first to the last also works.)
            s.back() = s.front();
        }

        cout << s << "\n";
    }

    return 0;
}