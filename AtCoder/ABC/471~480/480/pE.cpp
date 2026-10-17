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
ll n;

bool chk(ll a,ll d,int len){
    ll ans=1;
    for(int i=0;i<len;i++){
        ll cur = a+i*d;
        if(ans>n/cur){
            return 0;
        }
        ans*=cur;
    }
    return 1;
}

ll bis(ll a,int len){
    ll l=0,r=1e9;
    ll ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(a,mid,len)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

ll f(int len){
    ll ans=0;
    for(int i=1;i<=1e6;i++){
        if(!chk(i,1,len)) break;
        ans+=bis(i,len);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    ll ans=0;
    REP(len,3,20){
        ans+=f(len);
    }
    cout << ans << '\n';
}

/*
len最多到19
固定a, d越大越難達成
*/