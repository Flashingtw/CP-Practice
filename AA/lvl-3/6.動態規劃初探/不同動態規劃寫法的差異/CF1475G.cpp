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
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n) cin>>a[i];
    sort(ALL(a));
    int mx = *max_element(ALL(a));
    vi cnt(mx+1);
    REP(i,0,n){
        cnt[a[i]]++;
    }
    vi dp(mx+1); //dp[i] 以i為因數 最多可以保留幾個數字?
    int an = 0;
    REP(i,1,mx+1){
        dp[i] += cnt[i]; //增加可保留數字
        an = max(an,dp[i]); //算答案
        for(int j=i+i;j<=mx;j+=i){
            dp[j] = max(dp[j],dp[i]); //往後推當前數字
         }
    }
    
    cout << (n - an) << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}