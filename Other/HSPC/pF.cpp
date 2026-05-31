#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const unsigned short INF = 65535;
const int N = 16450;
unsigned short dist[N][512][10];
struct EDGE{
    int u,type;
};
vector<EDGE> adj[N];
struct STATE{
    int u,d,mask,las;
    bool operator<(const STATE& oth) const{
        return d>oth.d;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k,a,b;
    cin>>n>>m>>k>>a>>b;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<512;j++){
            for(int k=0;k<10;k++) dist[i][j][k]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,type;
        cin>>u>>v>>type;
        type--;
        adj[u].push_back({v,type});
        adj[v].push_back({u,type});
    }
    priority_queue<STATE> pq;
    pq.push({a,0,0,9});
    dist[a][0][9]=0;
    int ans = INF;
    while(!pq.empty()){
        auto [u,d,mask,las] = pq.top();
        pq.pop();
        if(u==b){
            ans = min(ans,d);
        }
        if(d>dist[u][mask][las]) continue;
        for(auto [v,t]:adj[u]){
            int nd = d+1;
            if(las!=9&&t!=las) nd++;
            if(!(mask&(1<<t))) nd++;
            if(nd>=dist[v][mask|(1<<t)][t]) continue;
            pq.push({v,nd,mask|(1<<t),t});
            dist[v][mask|(1<<t)][t] = nd;
        }
    }
    cout << ans << '\n';
}