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

const int N = 2e5+5;

int p[N],l[N],r[N];
vi adj[N],dep[N];
int cnt;
void dfs(int u,int d){
    l[u] = ++cnt;
    dep[d].push_back(cnt);
    for(auto v:adj[u]){
        dfs(v,d+1);
    }
    r[u] = cnt;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    rep(i,2,n+1){
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--){
        int U,D;
        cin>>U>>D;
        auto i1 = lower_bound(all(dep[D]),l[U])-dep[D].begin();
        auto i2 = upper_bound(all(dep[D]),r[U])-dep[D].begin();
        cout << i2-i1 << '\n';
    }
}