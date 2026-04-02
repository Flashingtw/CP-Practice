#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
char grid[505][505];
const int INF = 1e9+9;
int dis[505][505];//<dist,destroy>
bool vis[505][505];
int dx[] ={0,-1,0,1};
int dy[] ={1,0,-1,0};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++) grid[i][0] = grid[i][m+1] = '-';
    for(int i=0;i<=m+1;i++) grid[0][i] = grid[n+1][i] = '-';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis[i][j] = INF;
            cin>> grid[i][j];
        }
    }
    deque<pii> dq;
    dis[1][1] = grid[1][1]=='#';
    dq.push_back({1,1});
    while(!dq.empty()){
        auto [x,y] = dq.front();
        dq.pop_front();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(grid[nx][ny]=='-') continue;
            int cost = grid[nx][ny]=='#';
            int new_dis = dis[x][y]+cost;
            if(new_dis<dis[nx][ny]){
                dis[nx][ny] = new_dis;
                if(cost){
                    dq.push_back({nx,ny});
                }
                else{
                    dq.push_front({nx,ny});
                }
            }
        }
    }
    cout << dis[n][m];
}