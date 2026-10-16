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
struct ev{
    int t;
    int i,j;
};

int dist(ev a,ev b){
    return abs(a.i-b.i)+abs(a.j-b.j);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int r,n;
    cin>>r>>n;
    vector<ev> a(n+1);
    a[0] = {0,1,1};
    REP(i,1,n+1){
        cin>>a[i].t>>a[i].i>>a[i].j;
    }
    vi dp(n+1,-INF);
    dp[0]=0;
    REP(i,0,n+1){
        REP(j,max(i-2000,0),i){
            if(dist(a[i],a[j])<=a[i].t-a[j].t){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=0;
    REP(i,0,n+1) ans = max(ans,dp[i]);
    cout << ans << '\n';
}
/*
dp轉移思考
*/