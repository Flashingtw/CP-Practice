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
ll a[N];
ll p[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,v;
    cin>>n>>v;
    REP(i,1,n+1) cin>>a[i];
    REP(i,1,n+1) p[i] = p[i-1]+a[i];
    int cur=n;
    RREP(d,n,1){
        bool chk=0;
        REP(l,1,n+1){
            int r = l+d-1;
            if(r>n) break;
            if(p[r]-p[l-1]>v*d){
                chk=1;
                break;
            }
        }

        if(chk) break;
        cur=d;
    }
    cout << cur << '\n';
}