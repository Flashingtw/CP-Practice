#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct state{
    int a,t,d;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> col(n+1);
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<state> q;
    set<pii> s;
    q.push({1,n});
    s.insert({1,n});
    while(!q.empty()){
        auto [a,t,d] = q.front();
        q.pop();
        if(a==n&&t==1){
            cout << d << '\n';
            return;
        }
        for(int u:adj[a]){
            for(int v:adj[t]){
                if(col[u]!=col[v]){
                    if(s.find({u,v})!=s.end()) continue;
                    q.push({u,v,d+1});
                    s.insert({u,v});
                }
            }
        }
    }
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}