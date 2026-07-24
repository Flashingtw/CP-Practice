#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,k;
vector<int> bfs(int s,vector<vector<int>> &adj){
    vector<int> dist(n+1,-1);
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(dist[v]>=0) continue;
            q.push(v);
            dist[v]=dist[u]+1;
        }
    }
    return dist;
}
void solve(){
    cin>>n>>k;
    vector<vector<int>> adj(n+1);
    vector<int> cl(k);
    for(int i=0;i<k;i++) cin>>cl[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> f1 = bfs(cl[0],adj);
    int a=-1,b=-1,mx=-1;
    for(int i=0;i<k;i++) if(f1[cl[i]]>mx) mx=f1[cl[i]],a=cl[i];
    vector<int> d1 = bfs(a,adj);
    mx = -1;
    for(int i=0;i<k;i++) if(d1[cl[i]]>mx) mx=d1[cl[i]],b=cl[i];
    
    vector<int> d2 = bfs(b,adj);
    int ans=1e9;
    for(int i=1;i<=n;i++){
        ans = min(ans,max(d1[i],d2[i]));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}