#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll INF = 1e18;
const int N = 5e4+5;
vector<pii> adj[N];
ll n,m,k;

ll dijkstra(int s,int t){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<bool> vis(n+1,0);
    vector<ll> dist(n+1,INF);
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto [time,u] = pq.top();
        pq.pop();
        if(dist[u]<time) continue;
        for(auto [v,c]:adj[u]){
            ll d = dist[u]+c;
            if(dist[v]>d){
                dist[v]=d;
                pq.push({d,v});
            }
        }
    }
    return dist[t];
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        ll u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    int prev=1;
    bool chk=0;
    ll ans=0;
    for(int i=0;i<k;i++){
        int pos;
        cin>>pos;
        ll d = dijkstra(prev,pos);
        if(d==INF){
            chk=1;
        }
        else{
            ans+=d;
        }
        prev=pos;
    }
    ans+= dijkstra(prev,n);
    cout << (chk?-1:ans);
}