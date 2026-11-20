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
const int N = 1e6+5;
ll dp[N][2];
ll vis[N][2];
ll n,m;
const ll mod = 998244353;
ll f(int k,int typ){
    if(k==1&&typ==1) return m;
    if(k<=1&&typ==0) return 0;
    if(k<1) return 0;
    if(vis[k][typ]) return dp[k][typ];
    vis[k][typ]=1;
    if(typ){
        return dp[k][typ] = f(k-1,0)%mod;
    }
    else{
        return dp[k][typ] = ((m-1)*f(k-1,1)%mod + (m-2)*f(k-1,0)%mod)%mod;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    cout << f(n,0) << '\n';
}