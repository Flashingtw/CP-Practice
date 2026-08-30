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
string s;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
char dd[] = {'D','R','U','L'};

int vis[10][10];
int ans;
void dfs(int x,int y,int step){
    if(x==7&&y==1){
        if(step==48) ans++;
        return;
    }
    if(step==48) return;

    if(vis[x-1][y]&&vis[x+1][y]&&!vis[x][y-1]&&!vis[x][y+1]) return;
    if(!vis[x-1][y]&&!vis[x+1][y]&&vis[x][y-1]&&vis[x][y+1]) return;

    rep(d,0,4){
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(vis[nx][ny]) continue;
        if(s[step]!='?'&&s[step]!=dd[d]) continue;

        vis[nx][ny]=1;

        dfs(nx,ny,step+1);
        
        vis[nx][ny]=0;
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    rep(i,0,9){
        vis[i][0] = vis[i][8] = vis[0][i] = vis[8][i] = 1;
    }
    vis[1][1]=1;
    dfs(1,1,0);
    cout << ans << '\n';
}
/*
上下走過左右還沒 可剪
轉90度同理
*/