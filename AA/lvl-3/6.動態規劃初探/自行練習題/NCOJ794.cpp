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
const ll LINF = 9e18;

/*
dp[i][1] = max(dp[i-1][1]+a[i],a[i]);//不合法且最後i有選
dp[i][2] = max(dp[i-1][1],dp[i-1][2]);不合法且最後i沒有選
dp[i][3] = max(dp[i-1][3],dp[i-1][2]+a[i]);合法
*/


void solve() {
    int n;
    cin>>n;
    vector<vl> dp(n+5,vl(4,-LINF));
    vl a(n+1);
    REP(i,1,n+1) cin>>a[i];
    dp[1][0]=0;
    dp[1][1]=a[1];
    REP(i,1,n+1){
        dp[i][1] = max(dp[i-1][1]+a[i],a[i]);
        dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
        dp[i][3] = max(dp[i-1][3]+max(0LL,a[i]),dp[i-1][2]+a[i]);
    }
    cout << dp[n][3] << '\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}