#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
struct edg{
    int v,id;
};
vector<edg> adj[N];
int vis[N],del[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    int ans=m-n;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        ans++;
        vis[i]=1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto [v,id]:adj[u]){
                if(vis[v]) continue;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    cout << ans << '\n';
}