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
const int N = 1e5+5;
vector<int> adj[N];
int a[N],g[N],deg[N];
int p,q,r,m;
int typ(int idx){
    if(idx<=p) return 1;
    if(idx<=p+q) return 2;
    return 3;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>p>>q>>r>>m;
    REP(i,1,p+1) cin>>a[i];
    REP(i,1,q+1) {
        cin>>g[i];
        a[p+i] = -1;
    }
    
    REP(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> qu;
    vi dp(p+q+r+1);
    REP(i,1,p+q+r+1){
        if(deg[i]==0) {
            qu.push(i);
            dp[i] = 0;
        }
    }
    int ans=0;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        ans = max(ans,dp[u]);
        for(int v:adj[u]){
            int t = typ(v);
            if(t==2){
                if(a[v]==-1){
                    a[v] = a[u];
                    if(g[v-p]==4){
                        a[v] = !a[v];
                    }
                }
                else{
                    if(g[v-p]==1){
                        a[v] = a[u]&a[v];
                    }
                    else if(g[v-p]==2){
                        a[v] = a[u]|a[v];
                    }
                    else if(g[v-p]==3){
                        a[v] = a[u]^a[v];
                    }
                }
            }
            else if(t==3){
                a[v] = a[u];
            }
            if(--deg[v]==0) {
                qu.push(v);
                dp[v] = max(dp[v],dp[u]+1);
            }
        }
    }
    cout << ans-1 << '\n';
    REP(i,p+q+1,p+q+r+1){
        cout << a[i] << ' ';
    }
}