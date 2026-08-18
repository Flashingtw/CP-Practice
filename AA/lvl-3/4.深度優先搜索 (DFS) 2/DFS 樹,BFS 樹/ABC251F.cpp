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
vpii dfse,bfse;
int vis[N],vis1[N];
void dfs(int u){
    for(int v:adj[u]){
        if(vis1[v]) continue;
        vis1[v]=1;
        dfse.push_back({u,v});
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis1[1]=1;
    dfs(1);

    queue<int> q;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            vis[v]=1;
            q.push(v);
            bfse.push_back({u,v});
        }
    }

    for(auto [a,b]:dfse){
        cout << a << ' ' << b << '\n';
    }
    for(auto [a,b]:bfse){
        cout << a << ' ' << b << '\n';
    }
}