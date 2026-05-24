#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
    int n;
    vector<vector<long long>> mat;
    
    Matrix(int n) : n(n) {
        mat.assign(n, vector<long long>(n, 0));
    }
    
    Matrix operator*(const Matrix& other) const {
        Matrix res(n);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                for (int j = 0; j < n; ++j) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix a, long long b) {
    Matrix res(a.n);
    for (int i = 0; i < a.n; ++i) {
        res.mat[i][i] = 1; 
    }
    
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    long long L;
    
    if (!(cin >> N >> M >> L)) return 0;
    
    Matrix adj(N);
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v; 
        adj.mat[u][v] = 1;
    }
    
    Matrix ans = power(adj, L);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ans.mat[i][j];
            if (j < N - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}