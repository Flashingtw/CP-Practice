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

const int N = 3e5+5; 
vector<pil> adj[N];
int d[N];

ll dp[N][2];// 0 <= d-1 , 1 <= d

void dfs(int u,int p){
    vl a;
    ll base=0;
    for(auto [v,w]:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        base+=dp[v][1];
        a.push_back(dp[v][0]-dp[v][1]+w);
    }
    sort(ALL(a),greater());
    dp[u][1] = base;
    dp[u][0] = d[u]>=0?base:-LINF;
    for(int i=0;i<a.size()&&a[i]>0;i++){
        if(i<d[u]){
            dp[u][0]+=a[i];
        }
        if(i<=d[u]){
            dp[u][1]+=a[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,1,n+1){
        cin>>d[i];
        d[i]--;
    }
    REP(i,1,n){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,-1);
    cout << max(dp[1][0],dp[1][1]) << '\n';
}