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
const int N = 1e6+5;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vl a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    vl u(n,-LINF),nu(n,-LINF);
    u[0] = a[0];
    nu[1] = a[0];
    rep(i,2,n){
        u[i] = max(u[i-2],nu[i-2])+a[i];
        nu[i] = max(u[i-1],nu[i-1]);
    }
    cout << u[n-1] << '\n';
}