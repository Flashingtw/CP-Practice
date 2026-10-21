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
const int N = 2e5+5;
vpll adj[N];
ll vis[N];
ll chk[N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    priority_queue<pll,vpll,greater<pll>> pq;
    REP(i,1,n+1){
        chk[i]=chk[i]=-1;
    }
    REP(i,0,k){
        int a;
        cin>>a;
        pq.push({0,a});
        vis[a]=1;
    }
    REP(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    while(!pq.empty()){
        auto [t,u] = pq.top();
        pq.pop();
        if(u>n){
            u-=n;
            if(!vis[u]){
                vis[u]=1;
                continue;
            }
        }
        if(chk[u]>=0) continue;
        chk[u]=t;
        for(auto [v,w]:adj[u]){
            if(!vis[v]){
                pq.push({w+t,v+n});
            }
            else{
                pq.push({w+t,v});
            }
        }
    }
    REP(i,1,n+1){
        cout << chk[i] << ' ';
    }
}