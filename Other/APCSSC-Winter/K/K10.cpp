#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1005;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
vector<string> g(N);
int n,m,k;
vector<vector<int>> dist;

ll bfs(pii rp){
    dist.assign(n,vector<int>(m,-1));
    queue<pii> q;
    q.push(rp);
    dist[rp.first][rp.second]=0;
    ll res=0;
    while(!q.empty()){
        pii pos = q.front();
        q.pop();
        int ox = pos.first,oy = pos.second;
        for(int i=0;i<4;i++){
            int x = ox+dx[i],y = oy+dy[i];
            if(x<0||y<0||x>=n||y>=m||g[x][y]=='#'||dist[x][y]!=-1) continue;
            q.push({x,y});
            dist[x][y]=dist[ox][oy]+1;
            res+=dist[x][y];
        }
    }
    return res;
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>g[i];
    ll ans=0;
    while(k--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        ans+=bfs({x,y});
    }
    cout << ans;
}
