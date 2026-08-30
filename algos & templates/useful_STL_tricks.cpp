sort(a.rbegin(), a.rend());//sort desc
sort(a.begin(), a.end());//sort

a.erase(unique(a.begin(), a.end()), a.end());//remove duplicate
*max_element(a.begin(), a.end());//maximum element
*min_element(a.begin(), a.end());//minimum element
accumulate(a.begin(), a.end(), 0LL);//sum
reverse(a.begin(), a.end());//reverse
rotate(a.begin(),
       a.begin() + k,
       a.end());//rotate
//useful custom comparator
sort(v.begin(), v.end(),
     [](const auto& a, const auto& b) {

         if(a.first != b.first)
             return a.first < b.first;

         return a.second > b.second;
     });
//binary search stl
lower_bound(a.begin(), a.end(), x);
upper_bound(a.begin(), a.end(), x);
//count occurences
upper_bound(a.begin(), a.end(), x)
-
lower_bound(a.begin(), a.end(), x);

//stack
stack<int> st;

st.push(x);
st.pop();
st.top();
st.empty();
st.size();
for(int x : a) {

    while(!st.empty() && /* condition */)
        st.pop();

    st.push(x);
}



//queue
queue<int> q;

q.push(x);
q.pop();
q.front();
q.empty();
q.size();
//bfs pattern 
queue<int> q;
q.push(src);

while(!q.empty()) {

    int u = q.front();
    q.pop();

    for(auto v : adj[u]) {

        if(!vis[v]) {
            vis[v] = true;
            q.push(v);
        }
    }
}

//dequeue
deque<int> dq;

dq.push_front(x);
dq.push_back(x);

dq.pop_front();
dq.pop_back();

dq.front();
dq.back();