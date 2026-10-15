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
int n;

ll f(int s,int t,vl &a){
    vvl dp(n,vl(2));
    REP(i,s,t){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = a[i]+min(dp[i-1][0],dp[i-1][1]);
    }
    return min(dp[t-1][0],dp[t-1][1]);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vl a(n);
    REP(i,0,n) cin>>a[i];
    cout << min(a[0]+f(1,n,a),a[1]+(n>2?a[n-1]:0)+f(2,n-1,a)) << '\n';
}