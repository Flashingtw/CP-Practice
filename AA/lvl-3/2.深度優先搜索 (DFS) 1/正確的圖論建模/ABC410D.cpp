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

vpii adj[1005];
int vis[1005][2<<10];

int ans=INF;
int n,m;

void dfs(int u,int cur){
    if(u==n){
        ans = min(ans,cur);
    }
    for(auto [v,w]:adj[u]){
        if(vis[v][cur^w]) continue;
        vis[v][cur^w] =1;
        dfs(v,cur^w);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vis[1][0] = 1;
    dfs(1,0);
    cout << (ans==INF?-1:ans) << '\n';
}