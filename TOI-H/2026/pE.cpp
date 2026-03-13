#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 5e5+5;
int w[N];
vector<int> adj[N];
ll dp[N][3];
int n,m;

void dfs(int u,int p){
    vector<ll> mxchd;
    ll t=0;
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        t+=dp[v][0];
        mxchd.push_back(dp[v][2]-dp[v][0]);
    }
    dp[u][1]=dp[u][2]=w[u]+t;
    sort(mxchd.begin(),mxchd.end(),greater());
    int mn = min(m,(int)mxchd.size());
    for(int i=0;i<mn;i++){
        if(mxchd[i]<0) break;
        dp[u][1]+=mxchd[i];
    }
    mn = min(m-1,(int)mxchd.size());
    for(int i=0;i<mn;i++){
        if(mxchd[i]<0) break;
        dp[u][2]+=mxchd[i];
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]);
}