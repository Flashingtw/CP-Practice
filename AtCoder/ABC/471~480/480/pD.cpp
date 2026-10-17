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

ll f(ll i,vl &pre,vl &pre2,vl &idx){
    if(i==0) return 0;
    ll l = lower_bound(ALL(idx),i)-idx.begin()-1;
    ll d = pre[i-idx[l]];
    ll sum = pre2[l];
    return d+sum;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    REP(i,1,n+1) cin>>a[i];
    vl idx(n+1);
    vl pre(n+1),pre2(n+1);
    REP(i,1,n+1){
        idx[i] = idx[i-1]+i;
    }
    REP(i,1,n+1){
        pre[i]=pre[i-1]+a[i];
        pre2[i]=pre2[i-1]+pre[i];
    }
    
    REP(i,0,q){
        ll l,r;
        cin>>l>>r;
        
        cout << f(r,pre,pre2,idx)-f(l-1,pre,pre2,idx) << '\n';
    }
}
/*
B=(1,1,10,1,10,100,1,10,100,1000).
idx=(0,1,3,6,10)

Q
3 6
1 10
8 8



*/