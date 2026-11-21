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

int dp[105][105][2];
int vis[105][105][2];

int n;
int f(int i,int j,int p){
    if(vis[i][j][p]) return dp[i][j][p];
    vis[i][j][p]=1;
    int typ = (n-i-j)&1;
    int res;
    if(!typ){
        res = 0;
        if(i>0) res = res|f(i-1,j,p);
        if(j>0) res = res|f(i,j-1,p^1);
        return dp[i][j][p] = res;
    }
    else{
        res = 1;
        if(i>0) res = res&f(i-1,j,p);
        if(j>0) res = res&f(i,j-1,p);
        return dp[i][j][p] = res;
    }
}

void init(){
    REP(i,0,101){
        REP(j,0,101){
            dp[i][j][0] = dp[i][j][1] = 0;
            vis[i][j][0] = vis[i][j][1] = 0;
        }
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    vis[0][0][0] = vis[0][0][1] = 1;
}

void solve() {
    cin>>n;
    init();
    vi a(n+1);
    int cnt[2] = {};
    REP(i,1,n+1) {
        int a;
        cin>>a;
        cnt[abs(a)%2]++;
    }
    cout << (f(cnt[0],cnt[1],0)?"Alice":"Bob")<< '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}