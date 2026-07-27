#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int dist[20][20];
int dp[1<<16][16];

int main() {
    int n,m;
    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1 << m][m] = 0;
    // 1. 遍歷所有可能的「打卡清單」(mask)
    // 從小到大遍歷，確保算大 mask 時，小的 prev_mask 已經算好了
    for (int mask=0; mask<(1<<n); mask++) {

        // 2. 遍歷「現在停在哪裡」(u)
        for (int u=0; u<n; u++) {

            // 【檢查 1】如果 mask 裡根本沒有 u，這是不可能的（沒去過 u 怎麼可能停在 u？）
            if (!((mask>>u)&1)) continue;

            // 3. 算出「還沒來 u 之前的狀態」(prev_mask)
            // 用 XOR (^) 把 mask 第 u 位的 1 變成 0
            int prev_mask = mask^(1<<u);

            // 【檢查 2】如果拿掉 u 之後變成 0，代表 mask 裡原本只有 u 一個城市。
            // 這代表 u 是起點，起點的 dp 值在迴圈外面已經設為 0 了，不需要這裡算，跳過。
            if (prev_mask==0) continue;

            // 4. 尋找「上一個城市是誰」(v)
            // 我們要從 prev_mask 裡面找一個 v，當作跳板跳過來 u
            for (int v=0; v<n; v++) {

                // 【檢查 3】確保 v 真的存在於 prev_mask 裡
                // (也就是說，在去 u 之前，我們確實去過 v)
                if ((prev_mask >> v) & 1) {

                    // 5. 狀態轉移 (取最小值)
                    // 如果前一個狀態 dp[prev_mask][v] 是有路可走的 (不是無限大)
                    if (dp[prev_mask][v] != INF) {
                        // 嘗試更新：
                        // 目前解 = min(目前解,  走到 v 的成本 + 從 v 走到 u 的距離)
                        dp[mask][u] = min(dp[mask][u], dp[prev_mask][v] + dist[v][u]);
                    }
                }
            }
        }
    }
    //LOVE　GEMINI 這他媽誰會
    int full_mask = (1 << n) - 1;
    int ans = INF;
    for (int u = 0; u < n; u++) {
        // 嘗試從每一個終點 u 走回起點 m
        // 條件：必須能走到 full_mask 狀態且停在 u
        if (dp[full_mask][u] != INF) {
            // 加上從 u 回家 m 的距離
            ans = min(ans, dp[full_mask][u] + dist[u][m]);
        }
    }
    cout << ans;
}