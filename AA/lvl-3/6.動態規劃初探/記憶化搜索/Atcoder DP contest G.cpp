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
vi adj[N];
int deg[N],dp[N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    REP(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].PB(v);
        deg[v]++;
    }
    queue<int> q;
    REP(i,1,n+1){
        if(deg[i]==0) q.push(i);
    }
    int ans=0;
    while(!q.empty()){
        int u = q.front();
        ans = max(ans,dp[u]);
        q.pop();
        for(int v:adj[u]){
            if(--deg[v]==0){
                q.push(v);
                dp[v] = max(dp[v],dp[u]+1);
            }
        }
    }
    cout << ans << '\n';
}