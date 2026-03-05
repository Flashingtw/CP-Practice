#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char grid[4005][4005];

// 宣告一個結構來綁定「距離」和「顏色」
struct Node {
    int d, c;
};
// 第三維從 26 大幅縮小為 3 (只存第1近、第2近、第3近)
Node dp[2][4005][3];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 1; j <= m; j++){
            grid[i][j] = s[j-1];
        }
    }
    
    // 初始化第 0 列 (全部設為無限遠，顏色 -1)
    for(int j = 0; j <= m; j++){
        for(int k = 0; k < 3; k++) dp[0][j][k] = {1000000, -1};
    }
    
    int q;
    cin >> q;
    vector<ll> diff(4005, 0);
    
    for(int i = 1; i <= n; i++){
        int cur = i & 1;
        int pre = 1 - cur;
        
        // 初始化當前列的第 0 行
        for(int k = 0; k < 3; k++) dp[cur][0][k] = {1000000, -1};
        
        for(int j = 1; j <= m; j++){
            int lmt = min(i, j);
            int c_color = grid[i][j] - 'A';
            
            // 強制設定第一近的顏色就是自己踩著的 (距離為 0)
            dp[cur][j][0] = {0, c_color};
            dp[cur][j][1] = {1000000, -1};
            dp[cur][j][2] = {1000000, -1};
            
            // 負責更新前 3 名的 Lambda 函數 (極速寫法)
            auto add_color = [&](int d, int c) {
                if(c == -1 || c == c_color) return; // 忽略不存在或自己腳下的顏色
                
                if(dp[cur][j][1].c == c) {
                    if(d < dp[cur][j][1].d) dp[cur][j][1].d = d;
                }
                else if(dp[cur][j][2].c == c) {
                    if(d < dp[cur][j][2].d) {
                        dp[cur][j][2].d = d;
                        if(dp[cur][j][2].d < dp[cur][j][1].d) swap(dp[cur][j][2], dp[cur][j][1]);
                    }
                }
                else if(d < dp[cur][j][2].d) { // 遇到新的小距離，擠掉原本的第 3 名
                    dp[cur][j][2] = {d, c};
                    if(dp[cur][j][2].d < dp[cur][j][1].d) swap(dp[cur][j][2], dp[cur][j][1]);
                }
            };
            
            // 只拿上面和左邊的前 3 名來更新 (總共才 6 個候選人)
            for(int k = 0; k < 3; k++){
                add_color(dp[pre][j][k].d + 1, dp[pre][j][k].c);
                add_color(dp[cur][j-1][k].d + 1, dp[cur][j-1][k].c);
            }
            
            int v1 = dp[cur][j][1].d;
            int v2 = dp[cur][j][2].d;
            
            // 後面的差分陣列結算完全一樣！
            if(q == 1){
                int R = min(lmt, v1);
                if(1 <= R){
                    diff[R+1]--;
                    diff[1]++;
                }
            }
            else{
                int L = v1 + 1;
                int R = min(lmt, v2);
                if(L <= R){
                    diff[L]++;
                    diff[R+1]--;
                }
            }
        }
    }
    
    int mx = 0;
    for(int i = 1; i <= min(m, n); i++){
        diff[i] += diff[i-1];
        if(diff[i] > 0){
            mx = i;
        }
    }
    
    cout << mx << '\n';
    if(mx == 0){
        cout << '\n';
    }
    else{
        for(int i = 1; i <= mx; i++){
            cout << diff[i] << (i == mx ? "" : " ");
        }
        cout << '\n';
    }
}