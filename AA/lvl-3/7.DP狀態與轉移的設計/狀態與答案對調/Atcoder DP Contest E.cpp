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
const int N = 1e5+5;
ll dp[105][N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,w;
    cin>>n>>w;
    vpll a(n+1);
    REP(i,1,n+1) cin>>a[i].f>>a[i].s;
    REP(i,0,n+1){
        REP(j,1,N-4){
            dp[i][j]=LINF;
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=a[i].s) dp[i][j] = min(dp[i][j],dp[i-1][j-a[i].s]+a[i].f);
        }
    }
    int ans=0;
    for(int i=N-5;i>=1;i--){
        if(dp[n][i]<=w){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}