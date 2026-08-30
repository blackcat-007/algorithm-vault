using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& A,
                const Matrix& B) {

    int n = A.size();

    Matrix C(n, vector<long long>(n));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; j++) {

                C[i][j] =
                    (C[i][j] +
                     A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}
//power 
Matrix matpow(Matrix A, long long p) {

    int n = A.size();

    Matrix res(n, vector<long long>(n));

    for(int i = 0; i < n; i++)
        res[i][i] = 1;

    while(p) {

        if(p & 1)
            res = multiply(res, A);

        A = multiply(A, A);
        p >>= 1;
    }

    return res;
}