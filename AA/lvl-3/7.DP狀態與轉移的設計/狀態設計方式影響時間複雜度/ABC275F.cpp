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
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    REP(i,1,n+1) cin>>a[i];
    vector<vector<vi>> dp(n+1,vector<vi>(3005,vi(2,INF)));
    //dp[i][j] = 前i個數字 , 答案為j的最小操作次數, 0 i有被刪, 1 i沒被刪
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0][0] = 1;
        for(int j=1;j<=3000;j++){
            dp[i][j][0] = min(dp[i-1][j][0],dp[i-1][j][1]+1);
            if(j>=a[i]){
                dp[i][j][1] = min(dp[i-1][j-a[i]][0],dp[i-1][j-a[i]][1]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        int ans = min(dp[n][i][0],dp[n][i][1]);
        cout << (ans>=INF?-1:ans) << '\n';
    }
}