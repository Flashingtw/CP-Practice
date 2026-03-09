#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<long long>> Matrix;
typedef long long ll;
const ll INF = 2e18;
Matrix multiply(Matrix &A, Matrix &B) {
    Matrix C(2, vector<long long>(2));
    C[0][0] = max(A[0][0] + B[0][0] , A[0][1] + B[1][0]);
    C[0][1] = max(A[0][0] + B[0][1] , A[0][1] + B[1][1]);
    C[1][0] = max(A[1][0] + B[0][0] , A[1][1] + B[1][0]);
    C[1][1] = max(A[1][0] + B[0][1] , A[1][1] + B[1][1]);
    return C;
}

Matrix power(Matrix M, ll n) {
    Matrix res = {{0, -INF}, {-INF, 0}};
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
    ll n;
    cin>>n;
    ll a,b;
    cin>>a>>b;
    Matrix Base = {{b, b/2}, {a, a/2}};
    Matrix ans = power(Base, n);
    cout << max(ans[0][0],ans[1][0]) << endl;
}