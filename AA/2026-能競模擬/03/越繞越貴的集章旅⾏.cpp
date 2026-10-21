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
const int N = 205;
struct edg{
    int v;
    ll w;
};
struct state{
    int u;
    ll t;
    int d;
    bool operator<(const state &oth) const{
        return t>oth.t;
    }
};
vector<edg> adj[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    REP(i,0,m){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vvl dist(n+1,vl(n+1,LINF));
    priority_queue<state> pq;
    pq.push({s,0,0});
    dist[s][0]=0;
    while(!pq.empty()){
        auto [u,c,d] = pq.top();
        pq.pop();
        if(c>dist[u][d]) continue;
        for(auto [v,w]:adj[u]){
            ll nxt = c+d+w;
            if(dist[v][d+1]>nxt){
                pq.push({v,nxt,d+1});
                dist[v][d+1]=nxt;
            }
        }
    }
    ll ans=LINF;
    REP(i,0,n+1) ans = min(ans,dist[t][i]);
    
    cout << ans << '\n';
}