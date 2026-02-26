#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct state{
    int x,y;
    int dir;
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int new_dir(int dir ,char c){
    if(c=='A') return dir;
    if(c=='B') return dir^1;
    if(c=='C') return 3-dir;
}
void solve(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> grid(h+2,vector<char>(w+2,'#'));
    vector<vector<vector<int>>> dist(h+2,vector<vector<int>>(w+2,vector<int>(4,INF)));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
        }
    }
    deque<state> dq;
    dist[1][0][0] = 0;
    dq.push_back({1,0,0});
    while(!dq.empty()){
        auto [x,y,dir] = dq.front();
        dq.pop_front();
        int nx = x+dx[dir],ny=y+dy[dir];
        if(grid[nx][ny]=='#') continue;
        for(char i='A';i<='C';i++){
            int nd = new_dir(dir,i);
            int cost = !(i==grid[nx][ny]);
            if(dist[nx][ny][nd]>dist[x][y][dir]+cost){
                dist[nx][ny][nd] = (dist[x][y][dir]+cost);
                if(cost==0) dq.push_front({nx,ny,nd});
                else dq.push_back({nx,ny,nd});
            }
        }
    }
    cout << dist[h][w][0] << "\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}