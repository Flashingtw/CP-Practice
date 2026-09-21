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
    int n,k;
    cin>>n>>k;
    vi a(n),b(n);
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) cin>>b[i];
    vector<vi> dp(n,vi(2));
    dp[0][0] = dp[0][1] = 1;
    REP(i,1,n){
        if(dp[i-1][0]){
            if(abs(a[i]-a[i-1])<=k){
                dp[i][0] = 1;
            }
            if(abs(b[i]-a[i-1])<=k){
                dp[i][1] = 1;
            }
        }
        if(dp[i-1][1]){
            if(abs(a[i]-b[i-1])<=k){
                dp[i][0] = 1;
            }
            if(abs(b[i]-b[i-1])<=k){
                dp[i][1] = 1;
            }
        }
    }
    cout << ((dp[n-1][0]||dp[n-1][1])?"Yes":"No") << '\n';
}