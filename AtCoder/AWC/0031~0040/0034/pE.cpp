#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll dp[(1<<16)+5][16];
int main(){
    int n;
    cin>>n;
    vector<ll> p(n),w(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n-1;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        dp[1<<i][i] = 0;
    }
    for(int mask=1;mask<(1<<n);mask++){
        int cur=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) cur++;
        }
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                for(int v=0;v<n;v++){
                    if(!(mask&(1<<v))){
                        int nm = mask|(1<<v);
                        dp[nm][v] = max(dp[nm][v],dp[mask][u]+(abs(p[u]-p[v])*w[cur-1]));
                    }
                }
            }
        }
    }
    ll ans=-1;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[(1<<n)-1][i]);
    }
    cout << ans;
}