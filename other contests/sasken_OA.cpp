/*Problem Statement

You are given two strings s1 and s2.

You can perform the following operations on s1:

Delete characters from the beginning of s1.
Add characters to the end of s1.

Your goal is to transform s1 into a string that is an anagram of s2.

Find the minimum number of characters that need to be deleted and added.

Important

Since characters can only be deleted from the beginning of s1, the characters that remain from s1 must form a suffix.

The remaining suffix can then be extended by adding characters to its end so that the resulting string becomes an anagram of s2.

Example 1
Input:
s1 = "abcde"
s2 = "cdefg"


Output:
4
Explanation

Keep the suffix:

"cde"

Delete:

"ab"

Then add:

"fg"

So:

abcde
  ↓ delete "ab"


cde
  ↓ add "fg"


cdefg

Total operations:

2 deletions + 2 additions = 4
Example 2
Input:
s1 = "abcdef"
s2 = "def"


Output:
3
Explanation

Keep the suffix:

"def"

Delete:

"abc"

No characters need to be added.

deleted = 3
added = 0


answer = 3*/
#include <bits/stdc++.h>
using namespace std;

int minOperations(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> freq(256, 0);

    for (char c : s2) {
        freq[(unsigned char)c]++;
    }

    vector<int> window(256, 0);

    int l = n - 1;
    int kept = 0;

    while (l >= 0 && kept < m) {

        unsigned char c = s1[l];

        window[c]++;

        if (window[c] > freq[c]) {
            break;
        }

        kept++;
        l--;
    }

    int deleted = n - kept;
    int added = m - kept;

    return deleted + added;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;

    cin >> s1 >> s2;

    cout << minOperations(s1, s2) << '\n';

    return 0;
}