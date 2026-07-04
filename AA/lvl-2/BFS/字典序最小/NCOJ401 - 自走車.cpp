#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char sd[] = {'D','L','R','U'};
char step[105][105];
int last[105][105];
int vis[105][105];
struct state{
    int x,y;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<vector<char>> g(n+2,vector<char>(n+2,'X'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    queue<state> q;
    q.push({1,1});
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(vis[nx][ny]||g[nx][ny]=='X') continue;
            q.push({nx,ny});
            vis[nx][ny]=1;           
            step[nx][ny] = sd[d];
            last[nx][ny] = 3-d;
        }
    }
    int curx=n,cury=n;
    string ans;
    while(1){
        if(curx==1&&cury==1) break;
        ans.push_back(step[curx][cury]);
        int d = last[curx][cury];
        curx = curx+dx[d];
        cury = cury+dy[d];
    }
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
}