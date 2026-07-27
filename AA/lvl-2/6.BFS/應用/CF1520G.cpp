#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dd[] = {1,0,-1,0,1};
ll grid[2005][2005];
int n,m;
ll w;
struct state{
    int x,y;
};
void bfs(vector<vector<ll>> &dist,int sx,int sy,vector<ll> &s){
    queue<state> q;
    q.push({sx,sy});
    if(grid[sx][sy]>0) s.push_back(grid[sx][sy]);
    dist[sx][sy]=0;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int nx = x+dd[d];
            int ny = y+dd[d+1];
            if(grid[nx][ny]==-1||dist[nx][ny]<=dist[x][y]+w) continue;
            q.push({nx,ny});
            dist[nx][ny]=dist[x][y]+w;
            if(grid[nx][ny]>0){
                s.push_back(dist[nx][ny]+grid[nx][ny]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>w;
    for(int i=0;i<=n+1;i++) grid[i][0] = grid[i][m+1] = -1;
    for(int j=0;j<=m+1;j++) grid[0][j] = grid[n+1][j] = -1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>> dist_s(n+2,vector<ll>(m+2,1e18)),dist_e(n+2,vector<ll>(m+2,1e18));
    vector<ll> s,e;
    bfs(dist_s,1,1,s);
    bfs(dist_e,n,m,e);
    ll ans = 1e18;
    if(!s.empty()&&!e.empty()) ans = *min_element(s.begin(),s.end()) + *min_element(e.begin(),e.end());
    if(dist_s[n][m]!=1e18) ans = min(ans,dist_s[n][m]);
    cout << (ans==1e18?-1:ans) << '\n';
}