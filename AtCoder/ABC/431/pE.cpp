#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct state{
    int x,y;
    int dir;
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int get_new_dir(char c,int dir){
    if(c=='A') return dir;
    if(c=='B') return dir^1;
    if(c=='C') return 3-dir;
}
void solve(){
    int h,w;
    cin>>h>>w;
    vector grid(h+2,vector<char>(w+2));
    vector dist(h+2,vector(w+2,vector<int>(4,INF)));
    for(int i=0;i<=h+1;i++) grid[i][w+1]=grid[i][0]='#';
    for(int i=0;i<=w+1;i++) grid[h+1][i]=grid[0][i]='#';
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
        }
    }
    deque<state> dq;
    dq.push_back({1,0,0});
    dist[1][0][0]=0;
    while(!dq.empty()){
        auto [x,y,old_d] = dq.front();
        dq.pop_front();
        int nx=x+dx[old_d],ny=y+dy[old_d];
        if(grid[nx][ny]=='#') continue;
        for(char c:{'A','B','C'}){
            int new_dir=get_new_dir(c,old_d);
            int cost = !(c==grid[nx][ny]);
            
            if(dist[nx][ny][new_dir]>dist[x][y][old_d]+cost){
                dist[nx][ny][new_dir]=dist[x][y][old_d]+cost;
                if(cost==0) dq.push_front({nx,ny,new_dir});
                else dq.push_back({nx,ny,new_dir});
            }
        }
    }
    cout << dist[h][w][0] << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}