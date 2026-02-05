#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> adj[N];
int deg[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) {
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int u=q.front();q.pop();
        res.push_back(u);
        for(int v:adj[u]){
            if(--deg[v]==0){
                q.push(v);
            }
        }
    }
    if(res.size()!=n){
        cout << "IMPOSSIBLE";
    }
    else{
        for(int i:res) cout << i<< " ";
    }
}