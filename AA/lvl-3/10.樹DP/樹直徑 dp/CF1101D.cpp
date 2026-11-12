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

int a[N];
vi adj[N];

vi prime[N];

void init(){
    for(int i=2;i<N;i++){
        if(!prime[i].empty()) continue;
        for(int j=i;j<N;j+=i){
            prime[j].push_back(i);
        }
    }
}

map<int,int> dp[N];
int ans;
void dfs(int u,int p){
    for(int i:prime[a[u]]){
        dp[u][i]=1;
    }
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        for(int i:prime[a[u]]){
            for(int j:prime[a[v]]){
                if(i!=j) continue;
                ans = max(ans,dp[u][i]+dp[v][i]);
                dp[u][i] = max(dp[u][i],dp[v][i]+1);
            }
        }
    }
    for(auto [a,b]:dp[u]) ans = max(ans,b);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    init();
    int n;
    cin>>n;
    REP(i,1,n+1){
        cin>>a[i];
    }
    REP(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << ans << '\n';
}