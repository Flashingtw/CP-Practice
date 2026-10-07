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

ll fpow(ll base, ll p, ll mod){
    if(p==0) return 1;
    if(p&1){
        return base*fpow(base,p-1,mod) %mod;
    }
    else{
        ll a = fpow(base,p/2,mod);
        return (a*a)%mod;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    ll a,b;
    cin>>a>>b;
    for(int i=2;i<a;i++){
        if(fpow(a,b,i)%i==1){
            cout << i << '\n';
            return 0;
        }
    }
}