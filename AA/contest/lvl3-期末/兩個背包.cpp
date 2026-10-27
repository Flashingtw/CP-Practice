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
const int N = 105;
const ll mod = 998244353;
int b,n,q;
vl a[N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>b>>n>>q;
    REP(i,0,n){
        int b,v;
        cin>>b>>v;
        a[b].push_back(v);
    }
    vvl dp(b+1,vl(10005));
    for(int i=1;i<=b;i++){
        dp[i][0] = 1;
        for(int v:a[i]){
            for(int j=10000;j>=0;j--){
                if(j-v>=0) dp[i][j] = (dp[i][j]+dp[i][j-v])%mod;
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,c;
        cin>>x>>y>>c;
        ll ans=0;
        for(int j=0;j<=c;j++){
            ans = (ans+dp[x][j]*dp[y][c-j])%mod;
        }
        cout << ans << '\n';
    }
}