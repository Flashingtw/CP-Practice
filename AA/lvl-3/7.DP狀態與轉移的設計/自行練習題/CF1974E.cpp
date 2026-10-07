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
void solve() {
    int m,x;
    cin>>m>>x;
    vpll a(m+1);
    ll MAX=5;
    REP(i,1,m+1){
        cin>>a[i].f>>a[i].s;
        MAX+=a[i].s;
    }
    vector<vl> dp(m+1,vl(MAX+5,-LINF));//dp[i][j] 為 在第i月取得j點快樂度的最大剩餘金錢
    dp[0][0]=0;
    REP(i,1,m+1){
        dp[i][0] = dp[i-1][0]+x;
        REP(j,1,MAX){
            dp[i][j] = dp[i-1][j]+x;
            if(j>=a[i].s&&dp[i-1][j-a[i].s]-a[i].f>=0){
                dp[i][j] = max(dp[i][j],dp[i-1][j-a[i].s]-a[i].f+x);
            }
        }
    }
    int cur=0;
    RREP(i,MAX,1){
        if(dp[m][i]>=0){
            cur=i;
            break;
        }
    }
    cout << cur << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}