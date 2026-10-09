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

struct state{
    int n;
    int p;
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(4*n+1),b(4*n+1);
    REP(i,1,4*n+1) {
        char c;
        cin>>c;
        cin>>b[i];
    }
    REP(i,1,4*n+1) {
        char c;
        cin>>c;
        cin>>a[i];
    }
    vector<vector<state>> dp(4*n+5,vector<state>(2,{0,1}));
    /*
        dp[i][0] = i回合棄牌的最大收益
        dp[i][1] = i回合翻牌的最大收益
    */
    REP(i,1,4*n+1){
        dp[i][0].n = max(dp[i-1][0].n,dp[i-1][1].n);
        
        if(dp[i][0].n==dp[i-1][0].n) dp[i][0].p = dp[i-1][0].p;
        else dp[i][0].p = dp[i-1][1].p;
        
        int u1 = dp[i-1][0].n+ (a[dp[i-1][0].p]==b[i]);
        int u2 = dp[i-1][1].n+ (a[dp[i-1][1].p]==b[i]);;
        if(u1>u2){
            dp[i][1] = {u1,dp[i-1][0].p+1};
        }
        else{
            dp[i][1] = {u2,dp[i-1][1].p+1};
        }
    }
    cout << max(dp[4*n][0].n,dp[4*n][1].n) << '\n';
}