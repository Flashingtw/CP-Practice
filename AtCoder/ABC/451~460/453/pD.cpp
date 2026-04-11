#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

char g[1005][1005];
int h,w;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char dc[] = {'R','D','L','U'};
bool chk=0;
bool vis[1005][1005][4];
void dfs(int x,int y,int d,string &s){
    if(g[x][y]=='#') return;
    if(g[x][y]=='G'){
        cout << "Yes" << '\n' << s << '\n';
        chk=1;
        return;
    }
    if(chk) return;
    int ban=5;
    if(g[x][y]=='x') ban = d;
    if(g[x][y]=='o'){
        if(chk) return;
        s.push_back(dc[d]);
        dfs(x+dx[d],y+dy[d],d,s);
        s.pop_back();
        return;
    }
    for(int dd=0;dd<4;dd++){
        if(chk) return;
        int nx = x+dx[dd];
        int ny = y+dy[dd];
        if(ban==dd) continue;
        if(vis[nx][ny][dd]) continue;
        vis[nx][ny][dd]=1;
        s.push_back(dc[dd]);
        dfs(nx,ny,dd,s);
        s.pop_back();
    }
}

int main(){
    cin>>h>>w;
    pii start;
    for(int i=0;i<=h+1;i++) g[i][0] = g[i][w+1] = '#';
    for(int j=0;j<=w+1;j++) g[0][j] = g[h+1][j] = '#';
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
            if(g[i][j]=='S') start={i,j};
        }
    }
    string s="";
    dfs(start.first,start.second,-1,s);
    if(!chk) {
        cout << "No";
    }
}