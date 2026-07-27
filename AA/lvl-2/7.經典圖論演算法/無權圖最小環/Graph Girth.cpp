#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2505;
int n,m;
vector<int> adj[N];
int ans=1e9,p[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    vector<int> dist(n+1);
    dist[s]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(v==p[u]) continue;
            if(dist[v]){
                ans = min(ans,dist[u]+dist[v]-1);
                continue;
            }
            q.push(v);
            dist[v]=dist[u]+1;
            p[v]=u;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    cout << (ans==1e9?-1:ans) << '\n';
}