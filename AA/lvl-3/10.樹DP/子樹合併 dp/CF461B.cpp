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
const int mod = 1e9+7;

vi adj[N];
int a[N];
ll dp[N][2];

void dfs(int u,int p){
    dp[u][0] = !a[u];
    dp[u][1] = a[u];
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        ll t0=0,t1=0;
        //不切
        t0 = (t0 + dp[u][0]*dp[v][0])%mod;  
        t1 = (t1 + dp[u][1]*dp[v][0])%mod;
        t1 = (t1 + dp[u][0]*dp[v][1])%mod;
        //切
        t0 = (t0 + dp[u][0]*dp[v][1])%mod;
        t1 = (t1 + dp[u][1]*dp[v][1])%mod;

        dp[u][0] = t0;
        dp[u][1] = t1;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,1,n){
        int edg;
        cin>>edg;
        adj[i].push_back(edg);
        adj[edg].push_back(i);
    }
    REP(i,0,n){
        cin>>a[i];
    }
    dfs(0,-1);
    cout << dp[0][1] << '\n';
}