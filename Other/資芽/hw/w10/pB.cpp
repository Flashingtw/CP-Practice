#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> dist(n, vector<int>(n, 0));
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d;
            cin >> d;
            dist[i][j] = d;
            dist[j][i] = d; 
        }
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    int num_states = 1 << n;
    vector<vector<int>> dp(num_states, vector<int>(n, INF));
    
    dp[1][0] = 0; 

    for (int s = 1; s < num_states; ++s) {
        if (!(s & 1)) continue; 
        
        for (int i = 0; i < n; ++i) {
            if (!(s & (1 << i))) continue; 
            if (s != 1 && i == 0) continue; 
            
            if (dp[s][i] == INF) continue;

            for (int j = 0; j < n; ++j) {
                if (s & (1 << j)) continue; 
                
                int next_s = s | (1 << j);
                dp[next_s][j] = min(dp[next_s][j], dp[s][i] + dist[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dp[num_states - 1][i] + dist[i][0]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}