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
int n;
ll dp[5005][5005];
ll a[5005],s[5005];

ll f(int l,int r){
    if(dp[l][r]!=-1e18) return dp[l][r];
    if(l==r) return a[l];
    return dp[l][r] = max(a[l]+s[r]-s[l]-f(l+1,r),a[r]+s[r-1]-s[l-1]-f(l,r-1));
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    REP(i,1,n+1){
        cin>>a[i];
    }
    REP(i,1,n+1){
        s[i] = s[i-1]+a[i];
    }
    REP(i,1,n+1){
        REP(j,1,n+1){
            dp[i][j] = -1e18;
        }
    }
    cout << f(1,n) << '\n';
}