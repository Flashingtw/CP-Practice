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
const int N = 4e5+5;
vpii adj[N];
int n,m;
int deg[N],vis[N];
ll ans=-LINF;
ll dfs(int u){
    vis[u]=1;
    ll cur=0;
    for(auto [v,w]:adj[u]){
        cur+=w;
        if(vis[v]) continue;
        cur += max(0LL,dfs(v));
        ans = max(ans,cur);
    }
    return cur;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    REP(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(!(deg[i]==0)||adj[i].empty()) continue;
        ans = max(ans,dfs(i));
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]&&!adj[i].empty()){
            queue<int> q;
            vis[i]=1;
            q.push(i);
            vector<int> v;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto [ve,w]:adj[u]){
                    v.push_back(w);
                    if(vis[ve]) continue;
                    vis[ve]=1;
                    q.push(ve);
                }
            }
            vector<ll> p;
            p.push_back(0);
            for(int i:v) p.push_back(p.back()+i);
            for(int i:v) p.push_back(p.back()+i);
            int sz = v.size();
            priority_queue<pll,vpll,greater<pll>> pq;
            pq.push({0,0});
            for(int i=1;i<SZ(p);i++){
                while(pq.top().s<i-sz) pq.pop();
                ans = max(ans,p[i]-pq.top().f);
                pq.push({p[i],i});
            }
        }
    }
    cout << ans << '\n';
}