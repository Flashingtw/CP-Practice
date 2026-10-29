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
    int n,k,x;
    cin>>n>>k>>x;
    vi a(n+1);
    REP(i,1,n+1) cin>>a[i];
    if(n/k>x){
        cout << -1 << '\n';
        return 0;
    }
    vvl dp(n+1,vl(x+1,-LINF));
    dp[0][0] = 0;
    vector<deque<int>> dq(x+1);
    dq[0].push_back(0);
    for(int i=1;i<=n;i++){
        for(int j=x;j>=1;j--){
            while(!dq[j-1].empty()&&dq[j-1].front()<i-k){
                dq[j-1].pop_front();
            }
            if(!dq[j-1].empty())dp[i][j] = max(dp[i][j],dp[dq[j-1].front()][j-1]+a[i]);
            if(dp[i][j]==-LINF) continue;
            while(!dq[j].empty()&&dp[dq[j].back()][j]<=dp[i][j]){
                dq[j].pop_back();
            }
            dq[j].push_back(i);
        }
    }
    ll ans=0;
    for(int i=n-k+1;i<=n;i++){
        ans = max(ans,dp[i][x]);
    }
    cout << ans << '\n';
}