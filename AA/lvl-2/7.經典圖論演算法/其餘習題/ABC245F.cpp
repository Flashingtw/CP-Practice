#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
//先找全部環,再用反向圖從每個點跑回去
const int N = 2e5+5;
vector<int> adj[N];
int deg[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        deg[u]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }
    int ans=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans++;
        for(int v:adj[u]){
            if(--deg[v]==0) q.push(v);
        }
    }
    cout << n-ans << '\n';
}