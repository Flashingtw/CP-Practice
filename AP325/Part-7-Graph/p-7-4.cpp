#include <bits/stdc++.h>
using namespace std;
#define N 505

int main() {
    int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
    char cb[N][N];
    int dis[N][N];
    int n,m;
    cin>>m>>n;
    for (int i=0;i<=m+1;i++) cb[i][0] = cb[i][n+1] = '1';//哨兵
    for (int i=0;i<=n+1;i++) cb[0][i] = cb[m+1][i] = '1';
    for (int i=0;i<=m+1;i++) for (int j=0;j<=n+1;j++) dis[i][j] = -1;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin>>cb[i][j];

    queue<pair<int,int>> q; //x,y
    q.push({1,1});
    dis[1][1]=0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int si = p.first,sj = p.second;
        for (int dir=0;dir<4;dir++) {
            int ni=si+di[dir],nj = sj+dj[dir];
            while (cb[ni][nj]=='0') {
                if (dis[ni][nj]==-1) {
                    dis[ni][nj] = dis[si][sj]+1;
                    q.push({ni,nj});
                }
                ni+=di[dir];
                nj+=dj[dir];
            }
        }
    }
    if (dis[m][n]>0) dis[m][n]--;
    cout << dis[m][n];
}