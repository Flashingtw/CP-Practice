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

int n,d;
bool chk(double tar,vi a){
    vector<double> p(n+1);
    REP(i,1,n+1) p[i] = p[i-1]+(1.0*a[i-1]-tar);
    double ans = 1e18;
    for(int r=d;r<=n;r++){
        int l = r-d;
        ans = min(ans,p[l]);
        if(p[r]-ans>=0) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>d;
    vi a(n);
    EACH(x,a) cin>>x;
    double l=0,r=101,ans;
    REP(i,0,100){
        double mid = (l+r)/2;
        if(chk(mid,a)){
            ans = mid;
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
/*
b[i] = a[i]-v;

S[r]-S[l-1] <= 0;
*/