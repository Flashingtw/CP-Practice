#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<pair<int,int>> dp(1<<n,{1e9,1e9});//pair<rounds,height>
    dp[0] = {1,0};
    //ALL MASK
    //00000000 -> 11111111
    for (int mask=1;mask<(1<<n);mask++) {
        for (int i=0;i<n;i++) {
            if ((mask>>i)&1) {//010101110100 >> 2 ->0101011101 &1 = true
                int prev = mask^(1<<i);//000100 ^ 100 -> 000000
                pair<int,int> option = dp[prev];
                if (option.second+w[i]<=x) {
                    option.second+=w[i];
                }
                else {
                    option.first++;
                    option.second=w[i];
                }
                dp[mask] = min(dp[mask],option);
            }
        }
    }
    cout << dp[(1<<n)-1].first << endl;
}