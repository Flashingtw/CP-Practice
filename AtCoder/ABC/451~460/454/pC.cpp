#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 3e5+5;
vector<int> adj[N];
int ans;
bool vis[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            q.push(v);    
            vis[v]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) ans++;
    }
    cout << ans;
}