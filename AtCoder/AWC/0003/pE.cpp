#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];

    vector<int> C(M);
    for (int i = 0; i < M; i++) cin >> C[i];
    int limit = (1 << N);
    vector<int> sum_w(limit, 0);

    for (int mask = 0; mask < limit; mask++) {
        for (int i = 0; i < N; i++) {
            if ((mask >> i) & 1) {
                sum_w[mask] += W[i];
            }
        }
    }

    vector<bool> dp(limit, false);
    dp[0] = true;

    for (int j = 0; j < M; j++) {
        int capacity = C[j];
        for (int mask = limit - 1; mask >= 0; mask--) {
            if (dp[mask]) continue;
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                if (sum_w[sub] <= capacity && dp[mask ^ sub]) {
                    dp[mask] = true;
                    break;
                }
            }
        }
    }
    if (dp[limit - 1]) cout << "Yes";
    else cout << "No";
}