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
vector<int> adj[N];

vector<int> a[N],b[N];
int chk[N];

void dfs(int u){
    for(int a:b[u]) if(chk[a]) chk[a]=2;
    for(int b:a[u]) chk[b]=1;
    for(int v:adj[u]) dfs(v);
    for(int b:a[u]) if(chk[b]==1) chk[b]=0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    rep(i,2,n+1){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    int q;
    cin>>q;
    rep(i,0,q){
        int x,y;
        cin>>x>>y;
        a[x].push_back(i);
        b[y].push_back(i);
    }
    dfs(1);
    rep(i,0,q){
        cout << (chk[i]==2) << '\n';
    }
}
/*
離線+回滾
*/