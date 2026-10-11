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
    vector<vi> dp(m+1,vector<int>(1<<n,-1));
    dp[0][0]=0;
    REP(i,1,m+1){
        int a,b;
        cin>>a>>b;
        int bs=0;
        while(b--){
            int k;
            cin>>k;
            k--;
            bs |= 1<<k;
        }
        
        REP(j,0,1<<n) dp[i][j] = dp[i-1][j];//先把狀態轉過來
        REP(j,0,1<<n) {// push DP
            if(dp[i][j]==-1) continue;
            if(dp[i][j|bs]==-1||dp[i][j|bs]>dp[i][j]+a){// j|bs 第一次 or j|bs 比現在這個大 就轉移
                dp[i][j|bs] = dp[i][j]+a;
            }
        }
    } 
    cout << dp[m][(1<<n)-1] << '\n';
}

