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
const int N = 5e5+5;
vi adj[N];
bool chk;
int vis[N];
int col[N];
pii dfs(int u,int c){
    pii cur={0,0};
    if(c) cur.s++;
    else cur.f++;
    for(int v:adj[u]){
        if(vis[v]&&col[v]==c){
            chk=1;
            return {0,0};
        }
        if(vis[v]) continue;
        vis[v]=1;
        col[v]=c^1;
        pii a = dfs(v,c^1);
        
        cur.f+=a.f;
        cur.s+=a.s;
    }
    return cur;
}
int sz;
ll ans;
int n,m;
vpii a;
//void rec(int idx,ll n0,ll n1){
//    if(idx==sz){
//        ans = max(ans,(n1*n0)-m);
//        return;
//    }
//    rec(idx+1,n0+a[idx].f,n1+a[idx].s);
//    rec(idx+1,n0+a[idx].s,n1+a[idx].f);
//}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    REP(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        col[i]=1;
        a.push_back(dfs(i,1));
    }
    if(chk){
        cout << -1 << '\n';
        return 0;
    }
    sz=SZ(a);
    //rec(0,0,0);

    vvi dp(sz+1,vi(n+1,0));
    dp[0][0]=1;
    REP(i,1,sz+1){
        REP(j,0,n+1){
            int n1 = j-a[i-1].f;
            int n2 = j-a[i-1].s;
            if(n1>=0&&dp[i-1][n1]) dp[i][j] = 1;
            if(n2>=0&&dp[i-1][n2]) dp[i][j] = 1;
        }
    }
    for(ll i=1;i<=n;i++){
        if(!dp[sz][i]) continue;
        ans = max(ans,i*(n-i)-m);
    }
    cout << ans << '\n';
}