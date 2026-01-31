#include <iostream>
#include <vector>

using namespace std;
const long long MOD = 1000000007;
typedef vector<vector<long long>> Matrix;

Matrix multiply(Matrix &A, Matrix &B) {
    Matrix C(2, vector<long long>(2));
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
    return C;
}

Matrix power(Matrix M, int n) {
    Matrix res = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2 == 1) {
            res = multiply(res, M);
        }
        M = multiply(M, M);
        n /= 2;
    }
    return res;
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        Matrix Base = {{1, 1}, {1, 0}};
        Matrix Ans = power(Base, n);
        cout << Ans[1][0] << endl;
    }

    return 0;
}