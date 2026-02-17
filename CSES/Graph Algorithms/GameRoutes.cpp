#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 1e9+7;
vector<int> adj[N];
int deg[N],d[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v:adj[u]){
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }
    d[1]=1;
    for(int u:topo){
        for(int v:adj[u]){
            d[v] = (d[v]+d[u])%mod;
        }
    }
    cout << d[n];
}