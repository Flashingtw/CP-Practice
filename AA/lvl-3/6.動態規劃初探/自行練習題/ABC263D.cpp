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
    ll n,l,r;
    cin>>n>>l>>r;
    vl a(n+1);
    REP(i,1,n+1) cin>>a[i];
    vl ldp(n+2,LINF),rdp(n+2,LINF);
    ldp[0]=0;
    rdp[n+1]=0;
    REP(i,1,n+1){
        ldp[i] = min(ldp[i-1]+a[i],i*l);
    }
    RREP(i,n,1){
        rdp[i] = min(rdp[i+1]+a[i],(n-i+1)*r);
    }
    ll ans=LINF;
    REP(i,0,n+1) ans = min(ans,ldp[i]+rdp[i+1]);
    
    cout << ans << '\n';
}