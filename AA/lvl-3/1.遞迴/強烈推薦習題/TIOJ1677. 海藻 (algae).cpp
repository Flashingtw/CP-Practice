#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

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
ll fib[105];

int n;
void rec(int a,int k){
    if(a==1) {
        cout << 0 << '\n';
        return;
    }
    if(a==2) {
        cout << 1 << '\n';
        return;
    }
    if(k<=fib[a-2]) rec(a-2,k);
    else rec(a-1,k-fib[a-2]);
}

void solve() {
    ll k;
    cin>>n>>k;
    if(fib[n]<k) {
        cout << -1 << '\n';
        return;
    }
    rec(n,k);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=100;i++){
        fib[i] = fib[i-1]+fib[i-2];
        if(fib[i]>2e9) fib[i] = 2e9;
    }
    while(t--) solve();
}