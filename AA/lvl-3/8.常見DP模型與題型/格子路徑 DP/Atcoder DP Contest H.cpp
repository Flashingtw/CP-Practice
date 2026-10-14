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
const int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w;
    cin>>h>>w;
    vvc a(h+1,vc(w+1));
    REP(i,1,h+1){
        REP(j,1,w+1){
            cin>>a[i][j];
        }
    }
    vvl dp(h+1,vl(w+1));
    dp[0][1] = 1;
    REP(i,1,h+1){
        REP(j,1,w+1){
            if(a[i][j]=='#') continue;
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout << dp[h][w] << '\n';
}