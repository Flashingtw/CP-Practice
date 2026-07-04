#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct state{
    int u;
    ll mx,mn;
};
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<ll> a(n+1);
    vector<int> vis(n+1);
    vector<ll> ans(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<state> q;
    q.push({1,a[1],0});
    vis[1]=1;
    ans[1]=a[1];
    while(!q.empty()){
        auto [u,lmx,lmn] = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            ll mx = a[v] - min(0LL,lmn);
            ll mn = a[v] - max(0LL,lmx);
            q.push({v,mx,mn});
            ans[v] = mx;
            vis[v] = 1;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve(); 
}