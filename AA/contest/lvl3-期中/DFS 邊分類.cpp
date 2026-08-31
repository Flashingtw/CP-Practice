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
const int N = 1e5+5;

vpii adj[N];

int vis[N],typ[N],in[N],t[N];
int timer;
void dfs(int u){
    t[u] = timer++;
    in[u]=1;
    for(auto [v,i]:adj[u]){
        if(in[v]){//back
            typ[i]=2;
            continue;
        }
        if(vis[v]){
            if(t[v]>t[u]) typ[i] = 3;//for
            else typ[i] = 4;//cross
            continue;
        }
        vis[v]=1;
        typ[i]=1;
        dfs(v);
    }
    in[u]=0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s;
    cin>>n>>m>>s;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
    }
    rep(i,1,n+1) sort(all(adj[i]));
    dfs(s);
    for(int i=0;i<m;i++) cout << typ[i];
}