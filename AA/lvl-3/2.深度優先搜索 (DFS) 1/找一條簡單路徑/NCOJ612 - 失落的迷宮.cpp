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

int g[55][55];
int vis[55][55];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vpii ans;

bool dfs(int x,int y){
    if(g[x][y]==3){
        ans.push_back({x,y});
        return 1;
    }
    rep(d,0,4){
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(vis[nx][ny]||g[nx][ny]==1) continue;
        vis[nx][ny] = 1;
        if(dfs(nx,ny)) {
            ans.push_back({x,y});
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    int sx,sy;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>g[i][j];
            if(g[i][j]==2){
                sx=i,sy=j;
            }
        }
    }
    rep(i,0,n+2) g[i][0] = g[i][m+1] = 1;
    rep(j,0,m+2) g[0][j] = g[n+1][j] = 1;
    vis[sx][sy]=1;
    dfs(sx,sy);
    reverse(all(ans));
    cout << ans.size() << '\n';
    for(auto [a,b]:ans){
        cout << a-1 << ' ' << b-1 << '\n';
    }
}