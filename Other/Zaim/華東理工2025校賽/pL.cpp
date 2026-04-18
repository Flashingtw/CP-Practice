#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
const int N = 1e5+5;

vector<int> adj[N];

ll dfs1(int u,int p,vector<ll> &sz){
    sz[u]=1;
    ll sum=0;
    for(int v:adj[u]){
        if(v==p) continue;
        sum += dfs1(v,u,sz)+sz[v];
        sz[u] += sz[v];
    }
    return sum;
}
void dfs2(int u,int p,vector<ll> &sz,vector<ll> &dT,int n){
    for(int v:adj[u]){
        if(v==p) continue;
        dT[v] = dT[u]-sz[v]+(n-sz[v]);
        dfs2(v,u,sz,dT,n);
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dG(n+1),dT(n+1),sz(n+1),d(n+1);
    for(int i=1;i<=n;i++) cin>>dG[i];
    dT[1] = dfs1(1,0,sz);
    dfs2(1,0,sz,dT,n);
    for(int i=1;i<=n;i++) d[i] = dT[i]-dG[i];
    vector<int> ans;
    for(int i=1;i<=n;i++){
        bool pk=1;
        bool chk=0;
        for(int v:adj[i]){
            if (d[v]>d[i]) pk = 0;
            if (d[v]<d[i]) chk = 1;
        }
        if(pk&&chk) ans.push_back(i);
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}