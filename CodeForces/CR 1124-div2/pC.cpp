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

void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n+1);
    REP(i,1,n+1){
        cin>>a[i];
    }
    ll sum=0;
    if(n<2*k-1){
        for(int i=1;i<=n-k+1;i++){
            sum+=max(a[i],a[n-i+1]);
        }
    }
    else{
        for(int i=1;i<=k-1;i++){
            sum+=max(a[i],a[n-i+1]);
        }
        for(int i=k;i<=n-k+1;i++){
            sum+=a[i];
        }
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
/*
觀察題
*/