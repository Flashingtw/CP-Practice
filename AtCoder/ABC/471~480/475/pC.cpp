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
    int n,s;
    ll l;
    cin>>n>>s>>l;
    vi a(n+1);
    REP(i,1,n){
        cin>>a[i];
    }

    vl pre,suf;
    pre.PB(0);
    suf.PB(0);
    REP(i,s,n){
        pre.PB(pre.back()+a[i]);
    }
    RREP(i,s-1,1){
        suf.PB(suf.back()+a[i]);
    }
    int cur=0;
    int ans=0;
    EACH(x,pre){
        if(2*x>l) break;
        int idx = prev(upper_bound(ALL(suf),l-2*x))-suf.begin();
        ans = max(ans,idx+cur);
        cur++;
    }
    cur=0;
    EACH(x,suf){
        if(2*x>l) break;
        int idx = prev(upper_bound(ALL(pre),l-2*x))-pre.begin();
        ans = max(ans,idx+cur);
        cur++;
    }
    cout << ans+1 << '\n';
}
/*
2*x > l , int 溢位
*/