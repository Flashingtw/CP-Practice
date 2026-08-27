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

int n,a,b;
void dfs1(int u,int p,int cur,set<int> &s){
    s.insert(cur);
    for(auto [v,w]:adj[u]){
        if(v==p||v==b) continue;
        dfs1(v,u,cur^w,s);
    }
}

bool dfs2(int u,int p,int cur,set<int> &s){
    if(u!=b&&s.find(cur)!=s.end()){
        return 1;
    }
    for(auto [v,w]:adj[u]){
        if(v==p) continue;
        if(dfs2(v,u,cur^w,s)) return 1;
    }
    return 0;
}

void solve() {
    cin>>n>>a>>b;
    rep(i,1,n+1) adj[i].clear();
    rep(i,0,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    set<int> s;
    dfs1(a,0,0,s);
    cout << (dfs2(b,0,0,s)?"YES":"NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}