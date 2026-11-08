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

ll a[N];
vector<pil> adj[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    REP(i,1,n+1){
        cin>>a[i];
    }
    REP(i,0,m){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w+a[v]});
        adj[v].push_back({u,w+a[u]});
    }
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    vl dist(n+1,LINF);
    dist[1] = a[1];
    pq.push({a[1],1});
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        if(w>dist[u]) continue;
        for(auto [v,t]:adj[u]){
            if(w+t<dist[v]){
                dist[v] = w+t;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout << dist[i] << ' ';
    }
}