#include <bits/stdc++.h>
using namespace std;
char grid[55][55];
int w[55][55];
int r,c,h0,K;
struct state{
    int x,y,k,step;
};
int mxhp[55][55][25];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int startX, startY, endX, endY;
int min_steps = -1;
int max_final_hp = -1;

void bfs(){
    queue<state> q;
    q.push({startX, startY, 0, 0});
    mxhp[startX][startY][0]=h0+w[startX][startY];
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int k = cur.k;
        int step = cur.step;
        int curhp = mxhp[x][y][k];
        if (min_steps != -1 && step > min_steps) {
            continue;
        }
        if(x==endX&&y==endY){
            if (min_steps == -1) {
                min_steps = step;
                max_final_hp = curhp;
            } 
            else if (step == min_steps) max_final_hp = max(max_final_hp, curhp);
            continue;
        }
        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != '#') {
                int nhp = min(h0,curhp + w[nx][ny]);
                if (nhp > 0 && nhp > mxhp[nx][ny][k]) {
                    mxhp[nx][ny][k] = nhp;
                    q.push({nx,ny,k,step+1});
                }
            }
        }
        if (k < K) {
            for (int dr = -2; dr <= 2; dr++) {
                for (int dc = -2; dc <= 2; dc++) {
                    int dist = abs(dr) + abs(dc);
                    if (dist > 2 || dist == 0) continue;
                    int nx = x + dr;
                    int ny = y + dc;
                    if (nx<0||nx>=r||ny<0||ny>=c||grid[nx][ny]=='#') {
                        continue;
                    }
                    bool bk = false;
                    if (dist == 2) {
                        if (abs(dr) == 2) {
                            int mid_x = x + (dr / 2);
                            if (grid[mid_x][y] == '#') bk = true;
                        } 
                        else if (abs(dc) == 2) { 
                            int mid_y = y + (dc / 2);
                            if (grid[x][mid_y] == '#') bk = true;
                        } 
                        else {
                            if (grid[x + dr][y] == '#' && grid[x][y + dc] == '#') {
                                bk = true;
                            }
                        }
                    }
                    if (bk) continue;
                    int nhp = min(h0,curhp + w[nx][ny]);
                    int nk = k + 1;
                    if (nhp > 0 && nhp > mxhp[nx][ny][nk]) {
                        mxhp[nx][ny][nk] = nhp;
                        q.push({nx,ny,nk,step+1});
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>r>>c>>h0>>K;
    state start;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='S') startX = i,startY = j ;
            else if (grid[i][j]=='E') endX = i,endY = j;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>w[i][j];
        }
    }
    for(int kk=0;kk<=K;kk++){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mxhp[i][j][kk]=-1;
            }
        }
    }
    bfs();
    if(min_steps==-1) cout << -1;
    else cout << min_steps << " " << max_final_hp;
}