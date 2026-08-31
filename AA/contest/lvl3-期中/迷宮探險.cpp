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
const int N = 1005;

vpii adj[N];
vi key[N];
int buy[N];

int mn[N][1030];
int ans[N];
void dfs(int u,int cur,int cost){
    for(int i:key[u]){
        cur|=(1<<i);
    }
    mn[u][cur]=cost;
    ans[u] = min(ans[u],mn[u][cur]);
    for(auto [v,a]:adj[u]){
        if(a!=-1&&!((cur>>a)&1)) {
            int nxc = cost+buy[a];
            int nxt = cur|(1<<a);
            if(mn[v][nxt]<=nxc) continue;
            mn[v][nxt] = nxc;
            dfs(v,nxt,nxc);
        }
        else{
            if(mn[v][cur]<=cost) continue;
            mn[v][cur]=cost;
            dfs(v,cur,cost);
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        ans[i]=INF;
        for(int ms=0;ms<(1<<k);ms++){
            mn[i][ms]=INF;
        }
    }
    for(int i=0;i<k;i++){
        int p;
        cin>>p>>buy[i];
        key[p].push_back(i);
    }
    for(int i=0;i<m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        adj[u].push_back({v,a});
    }
    dfs(0,0,0);
    for(int i=1;i<n;i++){
        cout << (ans[i]==INF?-1:ans[i]) << '\n';
    }
}
/*
類dijkstra, 相同[v][cur]可能會有不同的cost
*/