#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int p[N],vis[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            p[v]=u;
            q.push(v);
            vis[v]=1;
        }
    }
    int qu;
    cin>>qu;
    for(int i=0;i<qu;i++){
        vector<int> a;
        int cur;
        cin>>cur;
        while(cur){
            a.push_back(cur);
            cur = p[cur];
        }
        for(int i=a.size()-1;i>=0;i--) cout << a[i] << ' ';
        cout << '\n';
    }
}