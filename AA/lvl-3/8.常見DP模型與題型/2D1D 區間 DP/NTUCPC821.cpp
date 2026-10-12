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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;
ll dp[1005][1005];
int vis[1005][1005];
ll a[1005];

ll f(int l,int r){
    if(vis[l][r]) return dp[l][r];
    if(l+1==r) return 0;
    vis[l][r] = 1;
    dp[l][r] = 1e18;
    for(int k=l+1;k<r;k++){
        dp[l][r] = min(dp[l][r],f(l,k)+f(k,r)+a[l]*a[k]*a[r]);
    }
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,0,n+1) cin>>a[i];
    for(int len=2;len<=n;len++){
        for(int l=0;l+len<=n;l++){
            int r = l+len;
            dp[l][r] = LINF;
            for(int k=l+1;k<r;k++){
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
            }
        }
    }
    cout << dp[0][n] << '\n';
}