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
char g[1005][1005];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w,k;
    cin>>h>>w>>k;
    REP(i,1,h+1){
        REP(j,1,w+1){
            cin>>g[i][j];
        }
    }
    vvl dp(h+2,vl(w+2));
    vvl las(h+2,vl(w+2));
    dp[1][1] = 1;
    ll ans=0;
    REP(o,0,k+1){
        REP(i,1,h+1){
            REP(j,1,w+1){
                if(g[i][j]=='#'||(i==1&&j==1&&o==0)) continue;
                ll val = dp[i-1][j]+dp[i][j-1];
                if(o>0){
                    if(!(i+1==h&&j==w)) val += las[i+1][j];
                    if(!(i==h&&j+1==w)) val += las[i][j+1];
                }
                dp[i][j] = val%mod;
            }
        }
        ans = (ans+dp[h][w])%mod;
        dp.swap(las);
    }
    cout << ans << '\n';
}