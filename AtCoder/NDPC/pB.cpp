#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        topo.push_back(u);
        q.pop();
        for(int v:adj[u]){
            if(--deg[v]==0) q.push(v);
        }
    }
    vector<ll> dp(n+1);
    dp[1]=1;
    for(int u:topo){
        for(int v :adj[u]){
            dp[v] = (dp[v]+dp[u])%mod;
        }
    }
    cout << dp[n] << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}