#include <bits/stdc++.h>
using namespace std;
const ll mod = 998244353;
string s;

ll dp[5005][5005];

ll rec(int l,int r){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    return dp[l][r] = (((rec(l+1,r) + rec(l,r-1))%mod - rec(l+1,r-1) + (s[l]==s[r]?rec(l+1,r-1)+1:0))%mod+mod)%mod;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    int n = SZ(s);
    REP(i,0,n){
        REP(j,0,n){
            dp[i][j]=-1;
        }
    }
    REP(i,0,n){
        dp[i][i] = 1;
    }
    cout << rec(0,s.size()-1) << '\n';
}
/*
mod.. dp[i][j] 預設值
*/