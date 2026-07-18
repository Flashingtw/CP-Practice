#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
struct edg{
    int b;
    ll x,y;
};
struct state{
    int u;
    ll x,y;
};
vector<edg> adj[N];
int vis[N];
ll px[N],py[N];
bool chk[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        ll x,y;
        cin>>a>>b>>x>>y;
        adj[a].push_back({b,x,y});
        adj[b].push_back({a,-x,-y});
    }
    queue<state> q;
    q.push({1,0,0});
    px[1]=0;
    py[1]=0;
    while(!q.empty()){
        auto [u,x,y] = q.front();
        q.pop();
        chk[u]=1;
        for(auto [v,ax,ay]:adj[u]){
            ll nx = x+ax,ny = y+ay;
            if(vis[v]&&(nx!=px[v]||ny!=py[v])){
                chk[v]=0;
                continue;
            }
            if(vis[v]) continue;
            px[v]=nx;
            py[v]=ny;
            q.push({v,nx,ny});
            vis[v]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(chk[i]) cout << px[i] << ' ' << py[i] << '\n';
        else cout << "undecidable" << '\n';
    }
}