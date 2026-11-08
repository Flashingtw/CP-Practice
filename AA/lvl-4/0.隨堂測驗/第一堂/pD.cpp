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
const int N = 1e5+5;

struct edg{
    int v;
    ll h,d;
};

vector<edg> adj[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    REP(i,0,m){
        int u,v;
        ll h,d;
        cin>>u>>v>>h>>d;
        adj[u].push_back({v,h,d});
        adj[v].push_back({u,h,d});
    }
    priority_queue<vl,vvl,greater<vl>> pq;
    vector<map<ll,ll>> dist(n+1);
    dist[1][LINF]=0;
    pq.push({0,1,LINF});
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        int u = a[1];
        ll w = a[0],h = a[2];
        if(w>dist[u][h]) continue;
        for(auto [v,hi,dis]:adj[u]){
            if(h<hi) continue;
            if(dist[v].find(hi)==dist[v].end()||w+dis<dist[v][hi]){
                dist[v][hi] = w+dis;
                pq.push({w+dis,v,hi});
            }
        }
    }
    ll ans=LINF;
    for(auto [a,b]:dist[n]){
        ans = min(ans,b);
    }
    cout << ans << '\n';
}