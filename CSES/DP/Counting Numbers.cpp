#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][11][2];//[digit][num][zero?]
string s;
ll dfs(int pos,int prev,bool zero,bool limit) {//抵達邊界
    if (pos==s.size()) return 1;
    if (!limit&&dp[pos][prev+1][zero]!=-1) {
        return dp[pos][prev+1][zero];
    }
    int up = limit?(s[pos]-'0'):9;
    ll ans=0;
    for (int d=0;d<=up;d++) {
        if (!zero&&d==prev) continue;
        bool new_limit = limit&&(d==up);
        bool new_zero = zero&&(d==0);
        int new_prev = new_zero?-1:d;
        ans+=dfs(pos+1,new_prev,new_zero,new_limit);
    }
    if (!limit) dp[pos][prev+1][zero] = ans;
    return ans;
}
ll solve(ll x) {
    if (x<0) return 0;
    if (x==0) return 1;
    s = to_string(x);
    fill(&dp[0][0][0],&dp[0][0][0]+sizeof(dp)/sizeof(ll),-1);
    return dfs(0,-1,1,1);
}
int main() {
    ll a,b;
    cin>>a>>b;
    cout << solve(b)-solve(a-1);
}