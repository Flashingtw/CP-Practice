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
const ll mod = 998244353;

int n,s;
ll k;
ll a[505][505];

ll f(int c1){
    vvl dp(n+1,vl(s+1));
    for(int i=1;i<=s;i++){
        if(abs(a[2][i]-a[1][c1])<=k){
            dp[2][i] = 1;
        }
    }
    REP(i,3,n){
        REP(j,1,s+1){
            REP(o,1,s+1){
                if(abs(a[i][j]-a[i-1][o])<=k){
                    dp[i][j] = (dp[i][j]+dp[i-1][o])%mod;
                }
            }
        }
    }
    ll ans=0;
    REP(j,1,s+1){
        REP(o,1,s+1){
            if(abs(a[n][j]-a[n-1][o])<=k&&(abs(a[n][j]-a[1][c1])<=k)){
                dp[n][j] = (dp[n][j]+dp[n-1][o])%mod;
            }
        }
        ans= (ans+dp[n][j])%mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>s>>k;
    REP(i,1,n+1){
        REP(j,1,s+1){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=s;i++){
        ans = (ans+f(i))%mod;
    }
    cout << ans << '\n';
}