#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
bool vis[1010][1010];
pii from[1010][1010];
map<pii,char> dir={{{0,1},'R'},{{0,-1},'L'},{{1,0},'D'},{{-1,0},'U'}};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    pii start;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start={i,j};
        }
    }
    queue<pii> q;
    q.push(start);
    vis[start.first][start.second]=true;
    bool bt=false;
    pii cur;
    while(!q.empty()){
        pii pos = q.front();
        q.pop();
        int rx = pos.first,ry = pos.second;
        if(grid[rx][ry]=='B'){
            bt=true;
            cur=pos;
            break;
        }
        for(int d=0;d<4;d++){
            int nx = rx+dx[d],ny = ry+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]=='#') continue;
            if(!vis[nx][ny]){
                vis[nx][ny]=true;
                from[nx][ny]=pos;
                q.push({nx,ny});
            }
        }
    }
    if(!bt){
        cout << "NO";
        return 0;
    }
    vector<char> res;
    while(cur!=start){
        int x=cur.first;
        int y= cur.second;
        int frx = from[x][y].first;
        int fry = from[x][y].second;
        res.push_back(dir[{x-frx,y-fry}]);
        cur=from[x][y];
    }
    cout << "YES\n" << res.size() << "\n";
    for(int i=res.size()-1;i>=0;i--) cout << res[i];
}