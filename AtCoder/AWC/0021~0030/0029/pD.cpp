#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w>=k){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<int> dist(n+1,INF);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]==INF){
                q.push(v);
                dist[v]=dist[u]+1;
            }
        }
    }
    if(dist[n]==INF) cout << -1;
    else cout << dist[n];
}