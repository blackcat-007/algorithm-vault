sort(intervals.begin(), intervals.end());

vector<pair<int,int>> ans;

for(auto [l, r] : intervals) {

    if(ans.empty() || ans.back().second < l) {
        ans.push_back({l, r});
    }
    else {
        ans.back().second =
            max(ans.back().second, r);
    }
}