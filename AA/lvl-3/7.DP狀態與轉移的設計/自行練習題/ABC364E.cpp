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

int dp[85][85][10005];//dp[i][j][k]是前i個選j個甜度為k個時的最小總鹹度

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    fill(&dp[0][0][0],&dp[0][0][0]+sizeof(dp)/sizeof(dp[0][0][0]),INF);
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vi a(n+1),b(n+1);
    REP(i,1,n+1){
        cin>>a[i]>>b[i];
    }
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0][0]=0;
        for(int j=1;j<=i;j++){
            for(int k=0;k<=x;k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(k>=a[i]){
                    dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-1][k-a[i]]+b[i]);
                }
            }
        }
    }
    int ans=0;
    REP(j,1,n+1){
        for(int k=0;k<=x;k++){
            if(dp[n][j-1][k]<=y){
                ans = j;
            }
        }
    }
    cout << ans << '\n';
}