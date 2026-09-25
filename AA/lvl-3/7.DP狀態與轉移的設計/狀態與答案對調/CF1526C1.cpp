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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vl a(n+1);
    REP(i,1,n+1) cin>>a[i];
    vector<vl> dp(n+1,vl(n+1,-LINF));
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i]>=0) dp[i][j] = dp[i-1][j-1]+a[i];
            else{
                dp[i][j] = max(dp[i-1][j-1]+a[i],dp[i-1][j]);
                if(dp[i][j]<0) dp[i][j]=-LINF;
            }
        }
    }
    for(int i=n;i>=1;i--){
        if(dp[n][i]>=0){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}