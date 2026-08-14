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

vector<vl> a;  
int n;
ll x;
ll ans;

void dfs(int idx,ll cur){
    if(idx==n){
        if(cur==x) ans++; 
        return;
    }
    for(ll i:a[idx]){
        if(cur>x/i+1) continue;
        dfs(idx+1,cur*i);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>x;
    a.resize(n);
    rep(i,0,n){
        int k;
        cin>>k;
        rep(j,0,k){
            int b;
            cin>>b;
            a[i].pb(b);
        }
    }
    dfs(0,1);
    cout << ans << '\n';
}