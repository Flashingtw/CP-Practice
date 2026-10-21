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
    int n;
    cin>>n;
    vpii a(n);
    vl h(n+1);
    REP(i,0,n) {
        cin>>a[i].f;a[i].s=i+1;
        h[i+1] = a[i].f;
    } 
    sort(ALL(a));
    a.push_back({LINF,LINF});
    set<int> s = {0,n+1};
    vl l1(n+1),r1(n+1),l2(n+1),r2(n+1,n+1);
    REP(i,0,n){
        vector<int> v = {i};
        while(a[i].f==a[i+1].f){
            v.push_back(i+1);
            i++;
        }
        EACH(x,v){
            int idx = a[x].s;
            auto it = s.lower_bound(idx);
            r1[idx] = *it;
            if(r1[idx]!=n+1) r2[idx] = *next(it);
            l1[idx] = *prev(it);
            if(l1[idx]!=0) l2[idx] = *prev(prev(it));
        }
        EACH(x,v){
            s.insert(a[x].s);
        }
    }
    ll mx =0;
    REP(i,1,n+1){
        mx = max({mx,(r2[i]-l1[i]-1)*h[i],(r1[i]-l2[i]-1)*h[i]});
    }
    cout << mx << '\n';
}