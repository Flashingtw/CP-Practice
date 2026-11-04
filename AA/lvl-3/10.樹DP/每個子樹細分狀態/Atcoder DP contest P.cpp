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

const int N = 1e5+5;
const int mod = 1e9+7;

vi adj[N];
int vis[N];
ll dp[N][2];

void dfs(int u){
    dp[u][0] = dp[u][1] = 1;
    for(int v:adj[u]){
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v);
        dp[u][0] = (dp[u][0]*(dp[v][0]+dp[v][1]))%mod;
        dp[u][1] = (dp[u][1]*dp[v][0])%mod;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    vis[1]=1;
    dfs(1);
    cout << (dp[1][0]+dp[1][1])%mod << '\n';
}