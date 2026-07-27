#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int vis[N],deg[N],tr[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        tr[a]=1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==1&&!tr[i]) q.push(i); 
    }
    int ans = n;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans--;
        for(int v:adj[u]){
            if(tr[v]) continue;
            if(--deg[v]==1) q.push(v);
        }
    }
    cout << ans << '\n';
}