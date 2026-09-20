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

int n;
bool chk(int tar,vpll &a){
    int j=0;
    ll mn =INF,mx = -INF;
    REP(i,0,n){
        while(j<n&&a[i].f-a[j].f>=tar){
            mn = min(mn,a[j].s);
            mx = max(mx,a[j].s);
            j++;
        }
        if(mx-a[i].s>=tar||a[i].s-mn>=tar) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vpll a(n);
    REP(i,0,n) cin>>a[i].f>>a[i].s;
    sort(ALL(a));
    int l=0,r=1e9+9,ans=0;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(chk(mid,a)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << '\n';
}
/*
|min(abs(xi-xj),abs(yi-yj))| >= D
abs(xi-xj) >= D && abs(yi-yj) >= D
*/