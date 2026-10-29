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
int g[2005][2005];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi a(k+1);
    a[0] = 1;
    REP(i,1,k+1) cin>>a[i];
    REP(i,1,n+1){
        REP(j,1,n+1){
            cin>>g[i][j];
        }
    }
    vvl dp(k+1,vl(n+1,INF));
    dp[0][1] = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(dp[i-1][j]==INF) continue;
            dp[i][j] = min(dp[i][j],dp[i-1][j]+g[a[i-1]][a[i]]);
            dp[i][a[i-1]] = min(dp[i][a[i-1]],dp[i-1][j]+g[j][a[i]]);
        }
    }
    ll ans=INF;
    for(int i=1;i<=n;i++){
        if(dp[k][i]==INF) continue;
        ans = min(ans,dp[k][i]+g[a[k]][n]+g[i][n]);
    }
    cout << ans << '\n';
}