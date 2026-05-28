#include <bits/stdc++.h>
using namespace std;
int n;
int dfs(int u,int p,vector<int> &sz,vector<vector<int>> &adj){
    int ss=0;
    for(int v:adj[u]){
        if(v==p) continue;
        int s = dfs(v,u,sz,adj);
        ss+=s;
        sz[u] = max(sz[u],s); 
    }
    sz[u] = max(sz[u],n-ss-1);
    return ss+1;
}

void solve(){
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> sz(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1,sz,adj);
    for(int i=0;i<n;i++){
        if(sz[i]<=n/2) {
            cout << i << '\n';
            break;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}