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

char g[15][15];
int vis[15][15];
int h,w,k;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int ans;
void dfs(int x,int y,int s){
    if(s==k){
        ans++;
        return;
    }
    vis[x][y]=1;
    rep(d,0,4){
        int nx = x+dx[d],ny = y+dy[d];
        if(g[nx][ny]=='#'||vis[nx][ny]) continue;
        dfs(nx,ny,s+1);
    }
    vis[x][y]=0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>h>>w>>k;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<=h+1;i++) g[i][0] = g[i][w+1] = '#';
    for(int i=0;i<=w+1;i++) g[0][i] = g[h+1][i] = '#';
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(g[i][j]=='#') continue;
            dfs(i,j,0);
        }
    }
    cout << ans << '\n';
}