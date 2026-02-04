#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const ll INF = 1e18;
const int N = 100005;
int n,m;
vector<pli> adj[N][2];
ll dist[N][2];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dist[i][0] = INF;
    for(int i=1;i<=n;i++) dist[i][1] = INF;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][0].push_back({b,c});
        adj[b][1].push_back({a,c});
    }
    dist[1][0]=0;
    //pair<dist,num>
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        pli pos = pq.top();
        pq.pop();
        int d = pos.first;
        int u = pos.second;
        if(dist[u][0]<d) continue;
        for(pli ed:adj[u][0]){
            int v = ed.first;
            int cost = ed.second;
            if(dist[u][0]+cost<dist[v][0]){
                dist[v][0]=dist[u][0]+cost;
                pq.push({dist[v][0],v});
            }
        }
    }
    dist[n][1]=0;
    pq.push({0,n});
    while(!pq.empty()){
        pli pos = pq.top();
        pq.pop();
        int d = pos.first;
        int u = pos.second;
        if(dist[u][1]<d) continue;
        for(pli ed:adj[u][1]){
            int v = ed.first;
            int cost = ed.second;
            if(dist[u][1]+cost<dist[v][1]){
                dist[v][1]=dist[u][1]+cost;
                pq.push({dist[v][1],v});
            }
        }
    }
    ll ans=INF;
    for(int u=1;u<=n;u++){
        for(pli ed:adj[u][0]){
            int v = ed.first,cost = ed.second;
            ans = min(ans,dist[u][0]+dist[v][1]+cost/2);
        }
    }
    cout << ans;
}