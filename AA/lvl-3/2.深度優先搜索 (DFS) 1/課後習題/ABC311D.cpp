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

string g[205];

int vis[205][205];
int tou[205][205];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int,int);

void slide(int x,int y,int d){
    int nx=x,ny=y;
    while(g[nx][ny]!='#'){
        tou[nx][ny]=1;
        nx += dx[d];
        ny += dy[d];
    }
    dfs(nx-dx[d],ny-dy[d]);
}

void dfs(int x,int y){
    if(vis[x][y]) return;
    vis[x][y]=1;
    tou[x][y]=1;
    rep(i,0,4){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(g[nx][ny]=='#') continue;
        slide(nx,ny,i);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,0,n) cin>>g[i];
    dfs(1,1);
    int ans=0;
    rep(i,0,n){
        rep(j,0,m){
            if(tou[i][j]) ans++;
        }
    }
    cout << ans << '\n';
}
/*
定義好dfs每一步要做甚麼, 甚麼時候紀錄vis
*/