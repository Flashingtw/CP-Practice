#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct state{
    int t,id,r,c;
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n,k,t;
    cin>>m>>n>>k>>t;
    vector<vector<int>> grid(m+2,vector<int>(n+2));
    vector<vector<int>> a(m+2,vector<int>(n+2,INF));

    for(int i=0;i<=m+1;i++) grid[i][n+1] = grid[i][0] = -1;
    for(int i=0;i<=n+1;i++) grid[m+1][i] = grid[0][i] = -1;
    
    queue<state> q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
            if(grid[i][j]>0){
                q.push({0,grid[i][j],i,j});
                a[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [time,id,i,j] = q.front();
        q.pop();
        if(time==t) continue;
        if(id!=grid[i][j]) continue;
        for(int d=0;d<4;d++){
            int nx= i+dx[d],ny = j+dy[d];
            if(grid[nx][ny]==-1) continue;
            if(a[nx][ny]==time+1){
                if(id<grid[nx][ny]){
                    grid[nx][ny]=id;
                    a[nx][ny]=time+1;
                    q.push({time+1,id,nx,ny});
                }
            }
            else if(a[nx][ny]>time+1){
                grid[nx][ny]=id;
                a[nx][ny]=time+1;
                q.push({time+1,id,nx,ny});
            }
        }
    }
    vector<int> cnt(k+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]>0){
                cnt[grid[i][j]]++;
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout << cnt[i] << ' ';
    }
}