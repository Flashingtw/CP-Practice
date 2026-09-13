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
    int n,k;
    cin>>n>>k;
    vl a(n+1,LINF);
    vi cond(k);
    REP(i,0,k){
        cin>>cond[i];
    }
    EACH(x,cond){
        cin>>a[x];
    }
    vl dp(n+2,LINF);
    REP(i,1,n+1){
        dp[i] = min(dp[i-1]+1,a[i]);
    }
    RREP(i,n,1){
        dp[i] = min(dp[i],dp[i+1]+1);
    }
    REP(i,1,n+1){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}