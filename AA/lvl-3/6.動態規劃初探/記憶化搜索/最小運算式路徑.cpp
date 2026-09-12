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
const int N = 505;
char c[N][N];
ll w[N][N];
ll dp[N];
ll cnt(char c,ll a,ll b){
    if(max(a,b)>=LINF) return LINF;
    __int128 res;
    if(c=='+') res = (__int128)a+b;
    else res = (__int128)a*b;

    if(res>=LINF) return LINF;
    else return res;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>c[i][j]>>w[i][j];
        }
    }
    REP(i,1,n+1) dp[i] = LINF;
    dp[1]=1;
    REP(i,1,n+1){
        REP(j,i+1,n+1){
            dp[j] = min(dp[j],cnt(c[i][j],dp[i],w[i][j]));
        }
    }
    if(dp[n]>=LINF) cout << "ouo" << '\n';
    else cout << dp[n] << '\n';
}
/*
溢位問題...
*/