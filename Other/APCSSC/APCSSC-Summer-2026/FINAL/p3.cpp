#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e18+9;
const int N = 2e5+5;
struct edg{
    int v;
    ll w;
};
struct state{
    int u;
    ll d;
    bool used;
    bool operator<(const state& oth) const{
        return d>oth.d;
    }
};
vector<edg> adj[N];
vector<int> tlp[N];
ll dist[N][2];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        tlp[u].push_back(v);
        tlp[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dist[i][0] = dist[i][1] = INF;
    }
    priority_queue<state> pq;
    pq.push({1,0,0});
    dist[1][0] = 0;
    while(!pq.empty()){
        auto [u,d,used] = pq.top();
        pq.pop();
        if(dist[u][used]<d) continue;
        for(auto [v,c]:adj[u]){
            if(dist[v][used]<=d+c) continue;
            dist[v][used] = d+c;
            pq.push({v,d+c,used});
        }
        if(!used){
            for(int v:tlp[u]){
                if(dist[v][1]<=d) continue;
                pq.push({v,d,1});
                dist[v][1] = d;
            }
        }
    }
    ll ans = min(dist[n][0],dist[n][1]);
    cout << (ans==INF?-1:ans) << '\n';
}