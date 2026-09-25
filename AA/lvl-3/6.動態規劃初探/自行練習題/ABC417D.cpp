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
    vector<int> p(n),a(n),b(n);
    REP(i,0,n) cin>>p[i]>>a[i]>>b[i];
    vector<vi> dp(n+1,vi(1005));
    for(int i=0;i<=1000;i++) dp[n][i] = i;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1000;j++){
            int nx = (j<=p[i]?j+a[i]:max(0,j-b[i]));
            dp[i][j] = dp[i+1][nx];
        }
    }
    vector<ll> pre(n);
    pre[0] = b[0];
    REP(i,1,n) pre[i] = pre[i-1]+b[i];
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x<=1000){
            cout << dp[0][x] << '\n';
            continue;
        }
        int idx = lower_bound(ALL(pre),x-1000)-pre.begin();
        if(idx==n){
            cout << x-pre[n-1] << '\n';
        }
        else{
            cout << dp[idx+1][x-pre[idx]] << '\n';
        }
    }
}
// x - 1000 <= pre[i+1]
/*
狀態有限性 , 複習
*/