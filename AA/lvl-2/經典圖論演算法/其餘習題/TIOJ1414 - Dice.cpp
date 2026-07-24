#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        vector<vector<int>> g(n+2,vector<int>(m+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                g[i][j] = c-'0';
            }
        }
        vector<vector<int>> vis(n+2,vector<int>(m+2));
        int dc=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!g[i][j]||vis[i][j]) continue;
                dc++;
                queue<pii> q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    for(int d=0;d<8;d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];
                        if(!g[nx][ny]||vis[nx][ny]) continue;
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j]!=2||vis[i][j]==2) continue;
                cnt++;
                queue<pii> q;
                q.push({i,j});
                vis[i][j]=2;
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    for(int d=0;d<8;d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];
                        if(g[nx][ny]!=2||vis[nx][ny]==2) continue;
                        q.push({nx,ny});
                        vis[nx][ny]=2;
                    }
                }
            }
        }
        cout << dc << ' ' << cnt << '\n';
    }
}