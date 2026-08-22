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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n+1);
    rep(i,1,n+1) cin>>v[i];
    vi ans(n+1);
    int l=0;
    ll cur=0;
    for(int r=1;r<=n;r++){
        while(r-l>m){
            l++;
            if(ans[l]) cur-=v[l];
        }
        if(cur+v[r]<=k){
            cur+=v[r];
            ans[r]=1;
        }
    }
    for(int i=1;i<=n;i++) cout << (ans[i]?"Yes":"No") << '\n';
}