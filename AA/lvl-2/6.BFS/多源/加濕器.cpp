#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct state{
    int x,y;
    int d;
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w,d;
    cin>>h>>w>>d;
    vector<vector<int>> dist(h+2,vector<int>(w+2,1e9));
    vector<vector<char>> g(h+2,vector<char>(w+2,'#'));
    queue<state> q;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
            if(g[i][j]=='H') {
                q.push({i,j,0});
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto [x,y,ds] = q.front();
        q.pop();
        for(int dd=0;dd<4;dd++){
            int nx = x+dx[dd];
            int ny = y+dy[dd];
            if(g[nx][ny]=='#'||dist[nx][ny]!=1e9) continue;
            q.push({nx,ny,ds+1});
            dist[nx][ny]=ds+1;
        }
    }
    ll cnt=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(dist[i][j]<=d){
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}