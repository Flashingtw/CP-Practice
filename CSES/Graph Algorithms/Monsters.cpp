#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+9;
typedef pair<int,int> pii;
char grid[1010][1010];
char path[1010][1010];
int mstep[1010][1010];
int pstep[1010][1010];

int dx[]={0,-1,0,1}, dy[] = {1,0,-1,0};

int main(){
    int n,m;
    cin>>n>>m;
    queue<pii> q;
    pii player;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            mstep[i][j]=INF;
            pstep[i][j]=-1;
            cin>>grid[i][j];
            if(grid[i][j]=='M') {
                q.push({i,j});
                mstep[i][j]=0;
            }
            else if(grid[i][j]=='A') {
                pstep[i][j]=0;
                path[i][j]='N';
                player = {i,j};
            }
        }
    }
    //monster step
    while(!q.empty()){
        pii pos = q.front();
        q.pop();
        int x = pos.first,y=pos.second;
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]=='#') continue;
            if (mstep[nx][ny] != INF) continue;
            mstep[nx][ny] = mstep[x][y]+1;
            q.push({nx,ny});
        }
    }
    q.push(player);
    pii end;
    bool chk=false;
    while(!q.empty()){
        pii pos = q.front();
        q.pop();
        int x = pos.first,y=pos.second;
        if(x==0||x==n-1||y==0||y==m-1){
            if(pstep[x][y]<mstep[x][y]){
                chk=true;
                end = pos;
                break;
            }
        }
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]=='#') continue;
            if (pstep[x][y]+1>=mstep[nx][ny]||pstep[nx][ny] != -1) continue;
            pstep[nx][ny] = pstep[x][y]+1;
            if(d==0) path[nx][ny]='R';   
            if(d==1) path[nx][ny]='U';
            if(d==2) path[nx][ny]='L';
            if(d==3) path[nx][ny]='D';
            q.push({nx,ny});
        }
    }
    if(!chk){
        cout << "NO";
    }
    else{
        cout << "YES" << "\n";
        pii cur=end;
        vector<char> res;
        while(cur!=player){
            int x = cur.first,y = cur.second;
            res.push_back(path[x][y]);
            if(path[x][y]=='L') cur = {x+dx[0],y+dy[0]};
            if(path[x][y]=='D') cur = {x+dx[1],y+dy[1]};
            if(path[x][y]=='R') cur = {x+dx[2],y+dy[2]};
            if(path[x][y]=='U') cur = {x+dx[3],y+dy[3]};
        }
        reverse(res.begin(),res.end());
        cout << res.size() << "\n";
        for(char c:res) cout << c;
    }
}