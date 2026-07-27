#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 3e5+5;
vector<int> adj[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1);
    vis[1]=1;
    queue<int> q;
    int ans = 0;
    for(int a:adj[1]){
        q.push(a);
        vis[a]=1;
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
        ans = max(ans,cnt);
    }
    cout << n-ans << '\n';
}