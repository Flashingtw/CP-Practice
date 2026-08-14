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

vi adj[4010];
int n,m;
int vis[4010];

void init(){
    rep(i,1,n+1){
        vis[i] = vis[i+n] = 0;
    }
}
int cnt(){
    int cnt=0;
    rep(i,1,n+1) if(vis[i]||vis[n+i]) cnt++;
    return cnt;
}
void dfs(int u){
    for(int v:adj[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    rep(i,0,m){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(v+(c*n));
        if(!c){
            adj[u+n].push_back(v+n);
        }
    }
    int ans=0;
    rep(i,1,n+1){
        init();
        vis[i]=1;
        dfs(i);
        ans+=cnt();
    }
    cout << ans << '\n';
}
/*
不能帶著狀態下去
*/