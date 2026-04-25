#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> dp(n+1);
    int mx =0;
    for(int i=1;i<=k;i++){
        dp[i] = max(mx,v[i]);
        mx = max(mx,dp[i]);
    }
    for(int i=k+1;i<=n;i++){
        dp[i] = max(dp[i-k]+v[i],dp[i-1]);
    }
    cout << dp[n] << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}