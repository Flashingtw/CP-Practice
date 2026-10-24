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
vi adj[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    REP(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    REP(i,1,n+1) sort(ALL(adj[i]));
    deque<pii> q;
    q.push_back({s,0});
    vi vis(n+1),dist(n+1,1e9);
    vis[s]=1;
    dist[s]=1;
    while(!q.empty()){
        auto [u,d] = q.front();
        q.pop_front();
        for(int v:adj[u]){
            int w=(v==adj[u].front()?0:1);
            if(d+w>=dist[v]) continue;

            dist[v]=d+w;
            
            if(w==0) q.push_front({v,dist[v]});
            else q.push_back({v,dist[v]});
        }
    }
    if(dist[t]!=1e9) cout << dist[t] << '\n';
    else cout << -1 << '\n';
}