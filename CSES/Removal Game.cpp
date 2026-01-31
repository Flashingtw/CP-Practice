#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
ll dp[N][N];
int val[N];
ll premix[N];
ll get_sum(int i,int j) {
    return premix[j+1]-premix[i];
}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>val[i];
        premix[i+1] = premix[i]+val[i];
    }
    for (int len=1;len<=n;len++) {
        for (int i=0;i+len-1<n;i++) {
            int j = i+len-1;
            if (len==1) {
                dp[i][j] = val[i];
                continue;
            }
            ll total = get_sum(i,j);
            ll pick_left = total - dp[i+1][j];//總分-剩下的=我拿的
            ll pick_right = total - dp[i][j-1];
            dp[i][j] = max(pick_left,pick_right);
        }
    }
    cout << dp[0][n-1];
}