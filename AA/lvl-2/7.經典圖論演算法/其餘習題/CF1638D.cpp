#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int g[1005][1005];
int ckx[] = {0,0,1,1};
int cky[] = {0,1,0,1};
int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,1,1,0,-1,-1};
struct state{
    int x,y;
    int c;
};
int chk(int i,int j){
    int typ=-1;
    for(int d=0;d<4;d++){
        int nx = i+ckx[d];
        int ny = j+cky[d];
        if(g[nx][ny]!=-1){
            if(typ==-1) typ=g[nx][ny];
            else if(g[nx][ny]!=typ) return 0;
        }
    }
    return typ;
}
void clr(int i,int j,int c){
    for(int d=0;d<4;d++){
        int nx = i+ckx[d];
        int ny = j+cky[d];
        g[nx][ny]=-1;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    queue<state> q;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int c = chk(i,j);
            if(c>0){
                q.push({i,j,c});
                clr(i,j,c);
            }
        }
    }
    vector<state> ans;
    while(!q.empty()){
        auto [x,y,c] = q.front();
        ans.push_back(q.front());
        q.pop();
        for(int d=0;d<8;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            int c = chk(nx,ny);
            if(c>0){
                q.push({nx,ny,c});
                clr(nx,ny,c);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]!=-1){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(auto [x,y,c]:ans){
        cout << x << ' ' << y << ' ' << c << '\n';
    }
}