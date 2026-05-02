#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

struct state{
    int u,day;
};
int chk=0;
void dfs(state cur,int w,vector<vector<int>> &vis,vector<vector<int>> &adj,vector<string> &week){
    auto [u,d] = cur;
    vis[u][d]=1;
    if(chk) return;
    for(int v:adj[u]){
        if(week[v][(d+1)%w]=='x') continue;
        if(vis[v][(d+1)%w]==1) chk=1;
        if(vis[v][(d+1)%w]==2) continue;
        dfs({v,(d+1)%w},w,vis,adj,week);
    }
    vis[u][d]=2;
}

bool solve(){
    chk=0;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<string> week(n+1);
    int w;
    cin>>w;
    vector<vector<int>> vis(n+1,vector<int>(w+1));
    vector<int> a;
    for(int i=1;i<=n;i++) {
        cin>>week[i];
        if(week[i][0]=='o'){
            a.push_back(i);
        }
        adj[i].push_back(i);
    }
    for(int i:a){
        dfs({i,0},w,vis,adj,week);
    }
    if(chk) return 1;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout << "Yes\n";
        else cout << "No\n";
    }
}