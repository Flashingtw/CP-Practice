#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<double,double> pdd;
typedef pair<char,int> pci;
typedef pair<int,char> pic;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;
const int N = 2e5+5;
vi ans;
vi adj[N];
int vis[N],in[N],d[N],p[N];

bool dfs(int u,int dep){
    in[u]=1;
    vis[u]=1;
    d[u]=dep;
    for(int v:adj[u]){
     if(v==p[u]) continue;
     if(in[v]){
          if(!((d[v]-d[u])&1)){
               int cur = u;
               while(cur!=v){
                ans.push_back(cur);
                cur = p[cur];
               }
               ans.push_back(v);
               return 1;
          }
          continue;
     }
     if(vis[v]) continue;
     p[v]=u;
     if(dfs(v,dep+1)){
          return 1;
     }
    }
    in[u]=0;
    return 0;
}
void init(int n){
    rep(i,1,n+1){
        vis[i] = in[i] = d[i] = p[i] = 0;
        adj[i].clear();
    }
}
void solve() {
    ans.clear();
    int n,m;
    cin>>n>>m;
    init(n);
    rep(i,0,m){
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
    }
    dfs(1,0);
    if(ans.empty()) cout << -1 << '\n';
    else{
        cout << ans.size() << '\n';
        for(int i:ans) cout << i << ' '; 
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}