struct SparseTable {

    int n, LOG;
    vector<vector<int>> st;
    vector<int> lg;

    SparseTable(vector<int>& a) {

        n = a.size();

        LOG = 32 - __builtin_clz(n);

        st.assign(LOG, vector<int>(n));
        lg.resize(n + 1);

        for(int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        st[0] = a;

        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {

                st[j][i] =
                    min(st[j-1][i],
                        st[j-1][i + (1 << (j-1))]);
            }
        }
    }

    int query(int l, int r) {

        int j = lg[r-l+1];

        return min(st[j][l],
                   st[j][r-(1<<j)+1]);
    }
};