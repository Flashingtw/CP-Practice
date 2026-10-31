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
    int k;
    cin>>k;
    vi sc(k+1);
    REP(i,1,k+1) cin>>sc[i];
    string a,b;
    cin>>a>>b;
    int n = SZ(a);
    int m = SZ(b);
    a = ' '+a;
    b = ' '+b;
    if(a==b){
        cout << 0 << '\n';
        return 0;
    }
    vvi dp(n+1,vi(m+1,INF));
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=m;i++) dp[1][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(!(a[i]==b[j]))});
        }
    }
    if(dp[n][m]>k) cout << 0 << '\n';
    else cout << sc[dp[n][m]] << '\n';
}
/*
以為是水題,結果|a|,|b|<=5e4
*/