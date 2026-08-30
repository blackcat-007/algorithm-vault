vector<int> freq(26);

for(char c : s)
    freq[c - 'a']++;
//for arbitrary ASCII values
vector<int> freq(256);

for(char c : s)
    freq[(unsigned char)c]++;
//STRING PREFIX FREQUENCY
vector<vector<int>> pref(n + 1, vector<int>(26));

for(int i = 0; i < n; i++) {

    pref[i + 1] = pref[i];

    pref[i + 1][s[i] - 'a']++;
}
//QUERY FREQUENCY of character c in [l,r]:
int cnt =
    pref[r+1][c-'a']
    - pref[l][c-'a'];