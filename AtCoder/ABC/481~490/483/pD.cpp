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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vl a(n+1);
    REP(i,1,n+1){
        cin>>a[i];
    }
    //最後的點會在pre[i]
    vl pre(n+1);
    vl premx(n+1),premn(n+1);
    REP(i,1,n+1){
        pre[i] = pre[i-1]+a[i];
        premx[i] = max(premx[i-1],pre[i]);
        premn[i] = min(premn[i-1],pre[i]);
    }
    vl sufmx(n+1),sufmn(n+1);
    sufmx[n] = sufmn[n] = pre[n];
    RREP(i,n-1,1){
        sufmx[i] = max(sufmx[i+1],pre[i]);
        sufmn[i] = min(sufmn[i+1],pre[i]);    
    }
    ll ans=premx[n] - premn[n] + 1;;
    REP(i,1,n+1){
        int dif = -2*a[i];
        ll mx = max(premx[i-1],sufmx[i]+dif);
        ll mn = min(premn[i-1],sufmn[i]+dif);
        ans = max(ans,mx-mn+1);
    }
    cout << ans << '\n';
}