#include <bits/stdc++.h>
using namespace std;
#define N 102
#define oo 100000000
int mp[N][N];
bool vis[N][N] = {false};
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};

int main() {
    int n,m;
    cin>>m>>n;
    for (int i=0;i<=m+1;i++) vis[i][0]=vis[i][n+1]=true;
    for (int j=0;j<n+1;j++) vis[0][j]=vis[m+1][j]=true;
    int si,sj,imax=oo;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>mp[i][j];
            if (mp[i][j]<imax) {
                si = i;
                sj = j;
                imax = mp[i][j];
            }
        }
    }
    long long ans=0;
    while (1) {
        ans+=mp[si][sj];
        vis[si][sj] = true;
        imax=oo;
        int i,j;
        for (int dir=0;dir<4;dir++) {
            int ni = si+di[dir],nj = sj+dj[dir];
            if (!vis[ni][nj]&&mp[ni][nj]<imax) {
                imax = mp[ni][nj],i=ni,j=nj;
            }
        }
        if (imax==oo) break;
        si = i;
        sj = j;
    }
    cout << ans;
}