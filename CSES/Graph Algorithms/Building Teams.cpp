#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int n,m;
int ans[N];
bool chk;
void dfs(int u){
    for(int v:adj[u]){
        if(ans[v]==0){
            ans[v]=ans[u]==1?2:1;
            dfs(v);
        }
        else if (ans[v]==ans[u]){
            chk=true;
            return;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            ans[i]=1;
            dfs(i);
        }
    }
    if(chk){
        cout << "IMPOSSIBLE";
    }
    else for(int i=1;i<=n;i++) cout << ans[i] << " ";
}