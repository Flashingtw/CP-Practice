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
ll a[405];
ll pre[405];
ll dp[405][405];
int vis[405][405];

ll f(int l,int r){
    if(l==r){
        return 0;
    }
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    dp[l][r] = LINF;
    for(int k=l;k<r;k++){
        dp[l][r] = min(dp[l][r],f(l,k)+f(k+1,r)+ pre[r]-pre[l-1]);
    }
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,1,n+1){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    cout << f(1,n) << '\n';
}
/*
沒跟著定義做,然後亂把+放在奇怪的位置
*/