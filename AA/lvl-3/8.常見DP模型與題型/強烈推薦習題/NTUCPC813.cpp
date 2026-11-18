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
ll a[3005];
ll dp[3005][3005][2];
int vis[3005][3005][2];
int n;
ll x;
ll f(int l,int r,int t){
    if(l==r) return dp[l][r][t] = n*abs(a[l]-x);
    if(vis[l][r][t]) return dp[l][r][t];
    vis[l][r][t] = 1;
    int k = n-(r-l);
    if(!t){
        return dp[l][r][t] = min(f(l+1,r,1)+k*(a[r]-a[l]),f(l+1,r,0)+k*(a[l+1]-a[l]));
    }
    else{
        return dp[l][r][t] = min(f(l,r-1,0)+k*(a[r]-a[l]),f(l,r-1,1)+k*(a[r]-a[r-1]));
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>x;
    REP(i,1,n+1) cin>>a[i];
    sort(a+1,a+n+1);
    f(1,n,0);
    f(1,n,1);
    cout << min(dp[1][n][0],dp[1][n][1]) << '\n';
}
/*
sort後也是只需要關注附近兩個的轉移即可, 可用區間dp實作 非常優質
*/
