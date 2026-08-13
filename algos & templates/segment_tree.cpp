#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
private:
    struct Node {
        int val;

        Node(int v = 0) {
            val = v;
        }
    };

    int n;
    vector<Node> tree;

    // Change this according to the problem
    Node merge(Node left, Node right) {
        return Node(max(left.val, right.val));   // Example: Maximum
    }

    void build(int node, int start, int end, vector<int>& arr) {

        if (start == end) {
            tree[node] = Node(arr[start]);
            return;
        }

        int mid = (start + end) / 2;

        build(node * 2, start, mid, arr);
        build(node * 2 + 1, mid + 1, end, arr);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, int value) {

        if (start == end) {
            tree[node] = Node(value);
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(node * 2, start, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, end, idx, value);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {

        // No overlap
        if (r < start || end < l)
            return Node();

        // Complete overlap
        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        Node left = query(node * 2, start, mid, l, r);
        Node right = query(node * 2 + 1, mid + 1, end, l, r);

        return merge(left, right);
    }

public:
    SegmentTree(vector<int>& arr) {

        n = arr.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, arr);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};