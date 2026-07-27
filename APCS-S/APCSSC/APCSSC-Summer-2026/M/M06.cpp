#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
const ll mod = 998244353;
ll dp[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin>>v[i];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if (i-v[j]>=0) dp[i] = (dp[i] + dp[i-v[j]])%mod;
        }
    }
    cout << dp[n] << '\n';
}