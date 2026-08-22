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
int n,m;
const int N = 105;
int vis[N];
void dfs(int u){
    if(u==n){
        string s;
        cin>>s;
        exit(0);
    }
    int k;
    cin>>k;
    vi a(k);
    rep(i,0,k) cin>>a[i];
    for(int v:a){
        if(vis[v]) continue;
        vis[v]=1;
        cout << v << endl;
        dfs(v);
        cout << u << endl;
        cin>>k;
        rep(i,0,k) cin>>a[i];
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    vis[1]=1;
    dfs(1);
}