
//For lowercase English letters:
struct Trie {

    struct Node {
        int child[26];
        bool end;

        Node() {
            fill(child, child + 26, -1);
            end = false;
        }
    };

    vector<Node> tr;

    Trie() {
        tr.emplace_back();
    }

    void insert(string s) {

        int u = 0;

        for(char c : s) {

            int x = c - 'a';

            if(tr[u].child[x] == -1) {
                tr[u].child[x] = tr.size();
                tr.emplace_back();
            }

            u = tr[u].child[x];
        }

        tr[u].end = true;
    }

    bool search(string s) {

        int u = 0;

        for(char c : s) {

            int x = c - 'a';

            if(tr[u].child[x] == -1)
                return false;

            u = tr[u].child[x];
        }

        return tr[u].end;
    }
};
//Binary Trie — XOR Problems

struct BinaryTrie {

    struct Node {
        int child[2];

        Node() {
            child[0] = child[1] = -1;
        }
    };

    vector<Node> tr;

    BinaryTrie() {
        tr.emplace_back();
    }

    void insert(int x) {

        int u = 0;

        for(int b = 30; b >= 0; b--) {

            int bit = (x >> b) & 1;

            if(tr[u].child[bit] == -1) {
                tr[u].child[bit] = tr.size();
                tr.emplace_back();
            }

            u = tr[u].child[bit];
        }
    }

    int maxXor(int x) {

        int u = 0;
        int ans = 0;

        for(int b = 30; b >= 0; b--) {

            int bit = (x >> b) & 1;
            int want = bit ^ 1;

            if(tr[u].child[want] != -1) {
                ans |= (1 << b);
                u = tr[u].child[want];
            }
            else {
                u = tr[u].child[bit];
            }
        }

        return ans;
    }
};