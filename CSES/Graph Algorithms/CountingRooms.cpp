#include <iostream>
using namespace std;
int n,m;
const int MAX=2000;
string s[MAX];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void dfs(int x,int y) {
    s[x][y]='#';
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx<0||ny<0||nx>=n||ny>=m||s[nx][ny]=='#') {
            continue;
        }
        dfs(nx,ny);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    cin>>n>>m;
    for (int i = 0;i<n;i++) {
        cin>>s[i];
    }
    int ans = 0;
    for (int i =0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (s[i][j]!='#') {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans << '\n';
}