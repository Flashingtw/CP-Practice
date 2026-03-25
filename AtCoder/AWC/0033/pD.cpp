#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
vector<pii> adj[N];
int dist[N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) dist[i] = INF;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        auto [c,u] = pq.top();
        pq.pop();
        if(dist[u]<c) continue;
        for(auto [v,cost]:adj[u]){
            if(dist[v]>c+cost){
                if(c+cost>k) continue;
                pq.push({c+cost,v});
                dist[v]=c+cost;
            }
        }
    }
    if(dist[n]==INF){
        cout << -1;
    }
    else cout << dist[n];
}