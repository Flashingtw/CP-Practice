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

const int N = 5e5+5;
vi adj[N];
int vis[N],dp[N][2];
void dfs(int u){
    int mx = -1e9;
    dp[u][1]=1;
    for(int v:adj[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
        int best = max(dp[v][0],dp[v][1]);
        dp[u][1]+=best;
        dp[u][0]+=best;
        mx = max(mx,dp[v][0]-best);
    }
    dp[u][1]+=mx;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    vis[1]=1;
    dfs(1);
    cout << max(dp[1][0],dp[1][1]) << '\n';
}