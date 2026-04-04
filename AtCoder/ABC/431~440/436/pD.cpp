#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1005;
int h,w;
char grid[N][N];
bool vis[N][N],used[26];
int dis[N][N];
int dx[] = {0,-1,0,1},dy[]={1,0,-1,0};
vector<pii> word[26];
int main(){
    cin>>h>>w;
    for(int i=0;i<=h+1;i++) grid[i][0] = grid[i][w+1] = '#';
    for(int i=0;i<=w+1;i++) grid[0][i] = grid[h+1][i] = '#';
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
            dis[i][j]=-1;
            if(grid[i][j]!='.'&&grid[i][j]!='#'){
                int num = grid[i][j]-'a';
                word[num].push_back({i,j});
            }
        }
    }
    queue<pii> q;
    q.push({1,1});
    dis[1][1]=0;
    vis[1][1]=true;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(x==h&&y==w) break;
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(grid[nx][ny]!='#'&&!vis[nx][ny]){
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
        if(grid[x][y]!='.'){
            int num = grid[x][y]-'a';
            if(used[num]) continue;
            used[num]=true;
            for(auto [nx,ny]:word[num]){
                if(!vis[nx][ny]){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
        }
    }
    cout << dis[h][w];
}