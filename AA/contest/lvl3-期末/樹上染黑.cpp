#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define EB emplace_back
#define f first
#define s second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define RREP(i,a,b) for(int i=(a);i>=(b);--i)
#define EACH(x,a) for(auto &x : a)

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
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

const int INF = 1e9+9;
const ll LINF = (1LL<<62);

const int N = 2e5+5;
vi adj[N];
ll a[N];
int col[N];

pll dp[N][2];
int vis[N];

void dfs(int u){
    dp[u][1] = {1,a[u]};
    if(col[u]){
        dp[u][0] = {-LINF,-LINF};
    }
    for(int v:adj[u]){
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v);
        if(dp[v][0]==make_pair(-LINF,-LINF)){
            dp[u][1] = {-LINF,-LINF};
        }
        else if(dp[u][1].f != -LINF){
            dp[u][1].f += dp[v][0].f;
            dp[u][1].s += dp[v][0].s;
        }
        if(!col[u]){
            pll pr = max(dp[v][1],dp[v][0]);
            dp[u][0].f+=pr.f;
            dp[u][0].s+=pr.s;
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    string ccc;
    cin>>ccc;
    REP(i,1,n+1) {
        col[i]= (ccc[i-1]=='b');
    }
    REP(i,1,n+1) cin>>a[i];
    REP(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1]=1;
    dfs(1);
    pll ans = max(dp[1][0],dp[1][1]); 
    cout << ans.f << ' ' << ans.s << '\n';
}