#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int deg[N],vis[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++,deg[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]<k) {
            q.push(i);
            vis[i]=1;
        }
    }
    int ans=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans++;
        for(int v:adj[u]){
            if(vis[v]) continue;
            if(--deg[v]<k) {
                q.push(v);
                vis[v]=1;
            }
        }
    }
    cout << ans << '\n';
}