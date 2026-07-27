#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
struct state{
    int v;
    int eg,tot,mx;
};
struct edg{
    int v,w;
};
vector<edg> adj[N];
int vis[N];
state ans[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    queue<state> q;
    q.push({1,0,0,0});
    vis[1]=1;
    while(!q.empty()){
        auto [u,ed,tot,mx] = q.front();
        q.pop();
        ans[u] = {u,ed,tot,mx};
        for(auto [v,w]:adj[u]){
            if(vis[v]) continue;
            q.push({v,ed+1,tot+w,max(mx,w)});
            vis[v]=1;
        }
    }
    for(int i=2;i<=n;i++){
        state a = ans[i];
        cout << a.eg << ' ' << a.tot << ' ' << a.mx << '\n';
    }
}