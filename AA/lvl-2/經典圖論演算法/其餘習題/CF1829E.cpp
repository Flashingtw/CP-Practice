#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+2,vector<int>(m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!g[i][j]) continue;
            queue<pii> q;
            q.push({i,j});
            ll cur=g[i][j];
            g[i][j]=0;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if(!g[nx][ny]) continue;
                    q.push({nx,ny});
                    cur+=g[nx][ny];
                    g[nx][ny]=0;
                }
            }
            ans = max(ans,cur);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}