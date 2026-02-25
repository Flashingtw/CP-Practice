#include <bits/stdc++.h>
using namespace std;
vector<int> adj[105];
bool vis[105];
int match[105];
bool dfs(int u){
    for(int v:adj[u]){
        if(!vis[v]){
            vis[v]=1;
            if(match[v]==-1||dfs(match[v])){
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=m;i++) match[i]=-1;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int num;
            cin>>num;
            adj[i].push_back(num);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dfs(i)) ans++;
        for(int i=0;i<=m;i++) vis[i]=0;
    }
    cout << ans;
}