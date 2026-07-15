#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int grid[1005][1005];
int dist[1005][1005][2];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct state{
    int x,y,t;
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<=n+1;i++){
        dist[i][0][0] = dist[i][n+1][0] = dist[0][i][0] = dist[n+1][i][0] = -1;
        dist[i][0][1] = dist[i][n+1][1] = dist[0][i][1] = dist[n+1][i][1] = -1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){  
            dist[i][j][0] = dist[i][j][1] = 1e9;
            cin>>grid[i][j];
        }
    }
    queue<state> q;
    q.push({1,1,0}),q.push({1,1,1});
    dist[1][1][0] = dist[1][1][1] = 1;
    while(!q.empty()){
        auto [x,y,t] = q.front();
        q.pop();
        if(x==n&&y==n){
            cout << dist[x][y][t] << '\n';
            return 0;
        }
        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(dist[nx][ny][t^1]<=dist[x][y][t]+1) continue;
            bool p=0;
            if(t&&grid[nx][ny]>grid[x][y]){
                p=1;
            }
            else if ((!t)&&grid[nx][ny]<grid[x][y]){
                p=1;
            }
            if(p){
                q.push({nx,ny,t^1});
                dist[nx][ny][t^1] = dist[x][y][t]+1;
            }
        }
    }
    cout << -1 << '\n';
}