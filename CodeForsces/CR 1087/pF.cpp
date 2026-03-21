#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 3e5+5;
int max_dep[N],best[N],a[N];
vector<int> adj[N];

pii dfs(int u,int p,int de){
    best[u] = u;
    max_dep[u]=de;
    for(int v:adj[u]){
        if(v==p) continue;
        auto [d,id] = dfs(v,u,de+1);
        if(d>max_dep[u]){
            max_dep[u] = d;
            best[u] = id;
        }
        else if(d == max_dep[u]){
            best[u] = min(best[u],id);
        }
    }
    return {max_dep[u],best[u]};
}
pii far(int u, int p, int de) {
    pii res = {de, u};
    for (int v : adj[u]) {
        if (v == p) continue;
        pii sub = far(v,u,de+1);
        if (sub.first > res.first) {
            res = sub;
        }
    }
    return res;
}
void df(int u,int p,vector<ll> &ch,ll sum){
    sum+=a[u];
    bool chk=0;
    for(int v:adj[u]){
        if(v==p) continue;
        chk=1;
        if(best[v]==best[u]){
            df(v,u,ch,sum);
        }
        else{
            df(v,u,ch,0);
        }
    }
    if(!chk) ch.push_back(sum);
}
ll cal(int root,int k){
    dfs(root, 0, 0);
    vector<ll> ch;
    for(int v:adj[root]){
        df(v, root, ch, 0); 
    }
    sort(ch.begin(), ch.end(), greater<ll>());
    
    int sz = min(k-1,(int)ch.size());
    ll sum = a[root];
    for(int i=0;i<sz;i++) {
        sum += ch[i];
    }
    return sum;
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        max_dep[i] = 0;
        best[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int v1 = far(1,0,0).second;
    int v2 = far(v1,0,0).second;

    cout << max(cal(v1,k),cal(v2,k)) << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}