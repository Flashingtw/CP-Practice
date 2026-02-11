#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int mp[510][510];
int n,m;
int ans;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
void bfs(int ox,int oy){
    queue<pii> q;
    q.push({ox,oy});
    mp[ox][oy]=0;
    int cnt=0;
    while(!q.empty()){
        pii pos = q.front();
        q.pop();
        cnt++;
        int rx=pos.first,ry=pos.second;
        for(int d=0;d<4;d++){
            int nx=rx+dx[d],ny=ry+dy[d];
            if(nx<0||ny<0||nx>=n||ny>=m||!mp[nx][ny]) continue;
            q.push({nx,ny});
            mp[nx][ny]=0;
        }
    }
    ans = max(ans,cnt);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>mp[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mp[i][j]==1) {
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << ans;
}
