#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2005;
vector<int> adj[N];
int n,m;
int bfs(int s){
    vector<int> vis(n+1);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    int cnt=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int v:adj[u]){
            if(vis[v]) continue;
            q.push(v);
            vis[v]=1;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=bfs(i);
    }
    cout << ans << '\n';
}