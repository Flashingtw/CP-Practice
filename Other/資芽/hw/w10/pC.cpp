#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
    long long N, K, C;
    cin >> N >> K >> C;

    vector<long long> val(N);
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }

    vector<long long> dp(N, 0);
    deque<int> dq;
    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        while (!dq.empty() && dq.front() < i - K) {
            dq.pop_front();
        }

        long long best_prev = 0;
        if (!dq.empty()) {
            int j = dq.front();
            best_prev = dp[j] - C * (i - j);
        }

        dp[i] = val[i] + max(0LL, best_prev);
        ans = max(ans, dp[i]);

        long long V_i = dp[i] + C * i;
        while (!dq.empty() && (dp[dq.back()] + C * dq.back()) <= V_i) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
}