vector<int> prefix_function(string s) {

    int n = s.size();
    vector<int> pi(n);

    for(int i = 1; i < n; i++) {

        int j = pi[i-1];

        while(j > 0 && s[i] != s[j])
            j = pi[j-1];

        if(s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}
//pattern search
string t = pattern + "#" + text;

vector<int> pi = prefix_function(t);

for(int i = 0; i < t.size(); i++) {
    if(pi[i] == pattern.size()) {
        // match ends at i
    }
}