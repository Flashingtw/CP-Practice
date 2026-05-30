#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,-1,-1,0,1,1};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n+2,vector<char>(m+2));
    for(int i=0;i<=n+1;i++) g[i][0] = g[i][m+1] = '!';
    for(int i=0;i<=m+1;i++) g[0][i] = g[n+1][i] = '!';
    vector<vector<bool>> vis(n+2,vector<bool>(m+2));
    vector<vector<int>> dis(n+2,vector<int>(m+2));
    queue<pii> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool chk=0;
            for(int d=0;d<8;d++){
                int nx = i+dx[d];
                int ny = j+dy[d];
                if(g[nx][ny]=='!') continue;
                if(g[nx][ny]!=g[i][j]) {
                    chk=1;
                    break;
                }
            }
            if(!chk) continue;
            vis[i][j]=1;
            dis[i][j]=1;
            q.push({i,j});
        }
    }
    if(q.empty()){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << '.';
        }
            cout << '\n';
        }
        return 0;
    }

    while(!q.empty()){
        auto [a,b] = q.front();
        q.pop();
        for(int d=0;d<8;d++){
            int nx = a+dx[d];
            int ny = b+dy[d];
            if(vis[nx][ny]||g[nx][ny]!=g[a][b]) continue;
            q.push({nx,ny});
            vis[nx][ny]=1;
            dis[nx][ny] = dis[a][b]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='.') cout << (dis[i][j]&1?'.':'#');
            else cout << (dis[i][j]&1?'#':'.');
        }
        cout << '\n';
    }
}