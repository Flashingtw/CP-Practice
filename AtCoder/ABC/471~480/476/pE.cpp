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
const int N = 2e5+5;
int a[N];
struct SEG{
    int sz;
    vl mx,mn;
    SEG(int x) : sz(x),mx(4*x),mn(4*x) {};
    void pull(int idx){
        int lmx = mx[idx*2];
        int rmx = mx[idx*2+1];
        
        mx[idx] = (a[lmx] > a[rmx] ? lmx : rmx);
        
        int lmn = mn[idx*2];
        int rmn = mn[idx*2+1];
        
        mn[idx] = (a[lmn] < a[rmn] ? lmn : rmn);
    }
    void build(int idx,int l,int r){
        if(l==r){
            mx[idx] = l;
            mn[idx] = l;
            return;
        }
        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        pull(idx);
    }
    
    void set(int idx,int l,int r,int pos,int val){
        if(pos<l||r<pos) return;
        if(l==r){
            a[l] = val;
            return;
        }
        int mid = (l+r)/2;
        set(idx*2,l,mid,pos,val);
        set(idx*2+1,mid+1,r,pos,val);
        pull(idx);
    }

    pii query(int idx,int l,int r,int ql,int qr){
        if(qr<l || r<ql)
            return {-1,-1};
    
        if(ql<=l && r<=qr)
            return {mx[idx],mn[idx]};
    
        int mid = (l+r)/2;
    
        pii L = query(idx*2,l,mid,ql,qr);
        pii R = query(idx*2+1,mid+1,r,ql,qr);
    
        if(L.f == -1) return R;
        if(R.f == -1) return L;
    
        int mxp = (a[L.f] > a[R.f] ? L.f : R.f);
        int mnp = (a[L.s] < a[R.s] ? L.s : R.s);
    
        return {mxp,mnp};
    }
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    REP(i,1,n+1) cin>>a[i];
    SEG seg(n);
    seg.build(1,1,n);
    REP(i,0,m){
        int l,r;
        cin>>l>>r;
        auto [mxp,mnp] = seg.query(1,1,n,l,r);
        int mx = a[mxp];
        int mn = a[mnp];
        seg.set(1,1,n,mxp,mn);
        seg.set(1,1,n,mnp,mx);
    }
    REP(i,1,n+1){
        cout << a[i] << ' ';
    }
}