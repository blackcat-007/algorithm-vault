//next greater
vector<int> nge(n, -1);
stack<int> st;

for(int i = n - 1; i >= 0; i--) {

    while(!st.empty() && a[st.top()] <= a[i])
        st.pop();

    if(!st.empty())
        nge[i] = a[st.top()];

    st.push(i);
}
//next smaller
vector<int> nse(n, -1);
stack<int> st;

for(int i = n - 1; i >= 0; i--) {

    while(!st.empty() && a[st.top()] >= a[i])
        st.pop();

    if(!st.empty())
        nse[i] = a[st.top()];

    st.push(i);
}
//previous greater
stack<int> st;

for(int i = 0; i < n; i++) {

    while(!st.empty() && a[st.top()] <= a[i])
        st.pop();

    if(!st.empty())
        prevGreater[i] = a[st.top()];

    st.push(i);
}
//previous smaller
vector<int> prevSmaller(n, -1);
stack<int> st;

for(int i = 0; i < n; i++) {

    while(!st.empty() && a[st.top()] >= a[i])
        st.pop();

    if(!st.empty())
        prevSmaller[i] = a[st.top()];

    st.push(i);
}