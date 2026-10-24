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
const int N = 2e5+5;
vpii adj[N],radj[N];
const ll mod = 998244353;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    REP(i,0,m){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        radj[v].push_back({u,c});
    }
    queue<int> q;
    q.push(1);
    vi vis(n+1),dist(n+1);
    vis[1] = 1;
    dist[1] = 0;
    vvi d(n+1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        d[dist[u]].push_back(u);
        for(auto [v,c]:adj[u]){
            if(vis[v]) continue;
            vis[v]=1;
            dist[v] = dist[u]+1;
            q.push(v);
        }
    }
    vl ans(n+1);
    vl rk(n+1);
    rk[1]=0;
    ans[1]=0;
    vpll best(n+1,{LINF,LINF});
    for(int i=1;i<=n;i++){
        for(int v:d[i]){
            for(auto [u,c]:radj[v]){
                if(dist[u]+1!=dist[v]) continue;    
                pll now = {rk[u],c};
                if(now<best[v]){
                    best[v]=now;
                    ans[v]=(10LL*ans[u]+c)%mod;
                }
            }
        }
        sort(ALL(d[i]),[&](int a,int b){return best[a]<best[b];});
        int cnt=0;
        for(int j=0;j<SZ(d[i]);j++){
            if(j && best[d[i][j]]!=best[d[i][j-1]]){
                cnt++;
            }
            rk[d[i][j]]=cnt;
        }
    }
    for(int i=2;i<=n;i++){
        cout << ans[i] << '\n';
    }
    //走d步絕對比d-1步大 -> 1走到各個地方的最短路徑
    // x的值 一定是從某個可以到達x的 v的值+'c' 
}