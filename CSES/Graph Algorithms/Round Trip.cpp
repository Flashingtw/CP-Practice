#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,m;
vector<int> adj[N];

int vis[N],in[N],p[N];
vector<int> ans;
bool fnd;
void dfs(int u,int pa){
    if(fnd) return;
    p[u]=pa;
    vis[u]=1;
    in[u]=1;
    for(int v:adj[u]){
        if(fnd) return;
        if(vis[v]&&in[v]&&v!=pa){
            int cur=u;
            ans.push_back(v);
            while (cur != v) {
                ans.push_back(cur);
                cur = p[cur];
            }
            ans.push_back(v);
            fnd=true;
            return;
        }
        else if (vis[v]||v==pa) continue;
        else{
            dfs(v,u);
        }
    }
    in[u]=0;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n&&!fnd;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    if(fnd){
        cout << ans.size() << "\n";
        for(int i : ans) cout << i << " ";
    }
    else {
        cout << "IMPOSSIBLE";
    }
}