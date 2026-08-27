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
vi adj[N];
int vis[N];

ll dfs(int u){
    vis[u]=1;
    ll a=1;
    for(int v:adj[u]){
        if(vis[v]) continue;
        a+=dfs(v);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    ll ans=0;
    rep(i,1,n+1){
        ans+=dfs(i);
        rep(i,1,n+1) vis[i]=0;
    }
    cout << ans-n-m << '\n';
}