#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dd[] = {1,0,-1,0,1};
struct state{
    pii p;
    int d;
    bool operator<(state oth){
        return d>oth.d;
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> g(n+2,vector<char>(m+2,'#'));
    pii s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='.') s={i,j};
        }
    }
    vector<vector<int>> vis(n+2,vector<int>(m+2));
    queue<pii> q;
    q.push(s);
    vis[s.first][s.second]=1;
    vector<state> pos;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        pos.push_back({{x,y},vis[x][y]});
        for(int d=0;d<4;d++){
            int nx = x+dd[d];
            int ny = y+dd[d+1];
            if(g[nx][ny]=='#'||vis[nx][ny]) continue;
            q.push({nx,ny});
            vis[nx][ny]=vis[x][y]+1;
        }
    }
    sort(pos.begin(),pos.end());
    for(int i=0;i<k;i++){
        auto [x,y] = pos[i].p;
        g[x][y]='X';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << g[i][j];
        }
        cout << '\n';
    }
}
//有更好的寫法