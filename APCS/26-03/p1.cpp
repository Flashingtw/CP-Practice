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
const int N = 1e5+5;
int n,k;
pll a[N];

bool chk(ll tar){
    int cnt=1;
    ll cur=0;
    REP(i,1,n){
        ll nxt = cur+a[i].f-a[i-1].f + ((a[i-1].s<a[i].s)?(a[i].s-a[i-1].s)*2:0);
        if(nxt>tar){
            cnt++;
            cur=0;            
        }
        else{
            cur = nxt;
        }
    }
    return cnt<=k;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    
    REP(i,0,n) cin>>a[i].f;
    REP(i,0,n) cin>>a[i].s;
    sort(a,a+n);
    ll l = 0,r=1e18;
    ll ans=0;
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}