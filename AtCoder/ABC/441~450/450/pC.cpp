#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> g(h+2,vector<char>(w+2,'#'));
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
        }
    }
    queue<pii> q;
    int cnt=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(g[i][j]=='.'){
                int chk=1;
                g[i][j]='#';
                q.push({i,j});
                while(!q.empty()){
                    auto [x,y] = q.front();
                    if((x==1||x==h||y==1||y==w)) chk=0; 
                    q.pop();
                    for(int d=0;d<4;d++){
                        int nx=x+dx[d],ny=y+dy[d];
                        if(g[nx][ny]=='.'){
                            q.push({nx,ny});
                            g[nx][ny]='#';
                        }
                    }
                }
                if(chk) cnt++;
            }
        }
    }
    cout << cnt;
}