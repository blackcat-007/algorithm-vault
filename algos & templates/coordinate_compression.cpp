vector<int> v = a;

sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

for(int &x : a) {
    x = lower_bound(v.begin(), v.end(), x) - v.begin();
}

//1indexing
vector<int> v = a;
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
for(int &x : a) {
    x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
