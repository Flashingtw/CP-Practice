#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<ll> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%mod;
    }
    cout << dp[n] << '\n';
}