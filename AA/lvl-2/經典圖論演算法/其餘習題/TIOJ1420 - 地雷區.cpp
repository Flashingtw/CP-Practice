#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
vector<int> adj[50005];
int dx[] = {1,1,1,0,0,0,-1,-1,-1};
int dy[] = {0,1,-1,0,1,-1,0,1,-1};
map<pii,int> mp;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=c;i++){
        int x,y;
        cin>>x>>y;
        for(int d=0;d<9;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            int nxt = mp[{nx,ny}];
            mp[{nx,ny}]=i;
            if(!nxt) continue;
            adj[i].push_back(nxt);
            adj[nxt].push_back(i);
        }
    }
    vector<int> vis(c+1);
    int ans=0;
    for(int i=1;i<=c;i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        ans++;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:adj[u]){
                if(vis[v]) continue;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    cout << ans << '\n';
}