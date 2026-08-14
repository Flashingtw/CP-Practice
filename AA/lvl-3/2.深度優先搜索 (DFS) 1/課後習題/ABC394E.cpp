#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<double,double> pdd;
typedef pair<char,int> pci;
typedef pair<int,char> pic;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;

char g[105][105];
vector<pic> adj[105];
vector<pic> radj[105];
int n;
struct state{
    int x,y,d;
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    queue<state> q;
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
    vector<vector<int>> vis(n+1,vector<int>(n+1));
    rep(i,1,n+1) q.push({i,i,0}),vis[i][i]=1;
    rep(i,1,n+1){
        rep(j,1,n+1){
            cin>>g[i][j];
            if(g[i][j]!='-'){
                adj[i].push_back({j,g[i][j]});
                radj[j].push_back({i,g[i][j]});
                if(i!=j) q.push({i,j,1});
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        auto [x,y,d] = q.front();
        q.pop();
        dist[x][y] = d;
        for(auto [v1,c1]:radj[x]){
            for(auto [v2,c2]:adj[y]){
                if(vis[v1][v2]||c1!=c2) continue;
                vis[v1][v2]=1;
                q.push({v1,v2,d+2});
            }
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            cout << (dist[i][j]==1e9?-1:dist[i][j]) << ' ';
        }
        cout << '\n';
    }
}
/*
最短路徑->BFS
迴文往下走+往回走 -> 正/反向圖
若i,i有自環 不會有 v->u->i->i->u->v 這種狀況 因為他不走那個i,i是最快的 owob
*/