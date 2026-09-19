#include <bits/stdc++.h>
using namespace std;

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

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    ll x,y;
    cin >> x >> y;
    vl a(n), b(m);
    REP(i,0,n) cin >> a[i];
    REP(i,0,m) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    
    vl pa(n+1, 0);
    REP(i,0,n){
        pa[i+1] = pa[i] + a[i];
    }
    vl pb(m+1, 0);
    vl need(m+1, 0);
    
    REP(i,0,m){
        pb[i+1] = pb[i] + b[i];
        need[i+1] = need[i] + (b[i]+k-1) / k;
    }

    ll mon = x+y*k;
    int ans = 0;

    REP(i,0,m+1){
        if(need[i]>y) break;
        if(pb[i]>mon) break;

        ll re = mon-pb[i];
        int c = upper_bound(ALL(pa),re) - pa.begin() -1;
        ans = max(ans,i+c);
    }
    cout << ans << '\n';
}