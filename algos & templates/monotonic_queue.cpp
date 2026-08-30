//classic sliding window maximum problem
deque<int> dq;

for(int i = 0; i < n; i++) {

    while(!dq.empty() && dq.front() <= i-k)
        dq.pop_front();

    while(!dq.empty() && a[dq.back()] <= a[i])
        dq.pop_back();

    dq.push_back(i);

    if(i >= k-1)
        cout << a[dq.front()] << '\n';
}
//classic sliding window minimum problem
deque<int> dq;
for(int i = 0; i < n; i++) {

    while(!dq.empty() && dq.front() <= i-k)
        dq.pop_front();

    while(!dq.empty() && a[dq.back()] >= a[i])
        dq.pop_back();

    dq.push_back(i);

    if(i >= k-1)
        cout << a[dq.front()] << '\n';
}
