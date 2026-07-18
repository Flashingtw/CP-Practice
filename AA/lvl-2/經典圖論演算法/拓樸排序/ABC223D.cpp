#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int deg[N];
int vis[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> pre;
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
        if(!deg[i]){
            q.push(i);
            vis[i]=1;
        }
    }
    for(int i:pre) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        ans.push_back(u);
        for(int v:adj[u]){
            if(--deg[v]==0) q.push(v);
        }
    }
    if(ans.size()==n) for(int i:ans) cout << i << ' ';
    else cout << -1 << '\n';
}