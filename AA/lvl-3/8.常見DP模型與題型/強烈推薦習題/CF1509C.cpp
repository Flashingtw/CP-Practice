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
ll dp[2005][2005];
int vis[2005][2005];
ll a[2005];

ll f(int l,int r){
    if(l==r) return 0;
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    return dp[l][r] = min(f(l,r-1),f(l+1,r))+a[r]-a[l];
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    REP(i,1,n+1){
        cin>>a[i];
    }
    sort(a,a+n+1);
    cout << f(1,n) << '\n';
}
/*
sort後只需要考慮新增左邊或右邊的 因為跨一個人一定不會比較好(看到這句話之後你自己好好想想)
所以就只需要考慮一個區間 新增左邊,右邊 就變成區間dp了 owob 
所以sort一下是一個很好的思考點 尤其是他不需要去在意是誰 只在意結果的話
*/