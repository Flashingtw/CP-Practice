#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
vector<int> adj[N];
ll v[N],w[N];
ll path_v[N],path_w[N];
void dfs(int u,int p,ll sum,ll use){
    sum+=v[u];
    use+=w[u];
    path_v[u]=sum,path_w[u]=use;
    for(int nxt:adj[u]){
        if(nxt==p) continue;
        dfs(nxt,u,sum,use);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,ver;
        cin>>u>>ver;
        adj[u].push_back(ver);
        adj[ver].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    dfs(1,0,0,0);
    vector<ll> dp(k+1,0);
    for(int i=1;i<=n;i++){
        if(path_w[i]>k) continue;
        for(int j=path_w[i];j<=k;j++){
            dp[j]=max(dp[j],dp[j-path_w[i]]+path_v[i]);
        }
    }
    cout << dp[k] << '\n';
}