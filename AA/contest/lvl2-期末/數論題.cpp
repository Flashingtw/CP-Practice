#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
vector<int> adj[N];
int d[N];
int vis[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll a,b,m,qu;
    cin>>a>>b>>m>>qu;
    for(int i=0;i<m;i++){
        adj[(i+a)%m].push_back(i);
        adj[(i*b)%m].push_back(i);
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            q.push(v);
            vis[v]=1;
            d[v]=d[u]+1;
        }
    }
    while(qu--){
        int n;
        cin>>n;
        if(vis[n]) cout << d[n] << '\n';
        else cout << -1 << '\n';
    }
}