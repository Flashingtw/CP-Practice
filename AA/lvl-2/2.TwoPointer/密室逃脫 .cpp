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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    ll s;
    cin>>n>>s;
    vl a(n);
    REP(i,0,n) cin>>a[i];
    sort(ALL(a));
    //a[i]+a[j]+a[k]=s
    ll ans=0;
    for(int i=0;i<n;i++){
        int l=n-1,r=n-1;
        for(int j=i+1;j<n;j++){
            ll t = s-a[i]-a[j];
            //a[j]越大 t越小
            if(j>r) break;
            while(l>j&&a[l]>=t) l--;
            while(r>j&&a[r]>t) r--;
            ans+= max(0,r-max(j,l));
        }
    }
    cout << ans << '\n';
}