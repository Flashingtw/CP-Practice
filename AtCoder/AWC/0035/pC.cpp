#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int t[N];
int deg[N];
vector<int> adj[N];
bool vis[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]>t[i]){
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            deg[v]++;
            if(deg[v]>t[v]){
                q.push(v);
                vis[v]=1;
            }
        }
    }
    bool c=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cout << i << ' ';
            c=1;
        }
    }
    if(!c) cout << -1;
}