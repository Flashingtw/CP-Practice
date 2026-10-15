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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vl a(2*n);
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) a[i+n] = a[i];
    vvl dp(2*n,vl(2*n,-LINF));
    
    REP(i,0,2*n-1) dp[i][i+1] = 0;

    REP(len,3,n+2){
        REP(l,0,2*n-len+1){
            int r = l+len-1;
            REP(k,l+1,r){
                dp[l][r] = max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
            }
        }
    }
    ll ans=-LINF;
    REP(i,0,n){
        ans = max(ans,dp[i][i+n]);
    }
    cout << ans << '\n';
}