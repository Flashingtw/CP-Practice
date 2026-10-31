#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define EB emplace_back
#define f first
#define s second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define RREP(i,a,b) for(int i=(a);i>=(b);--i)
#define EACH(x,a) for(auto &x : a)

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
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

const int INF = 1e9+9;
const ll LINF = (1LL<<62);
char g[505][505];
int vis[505][505];
int ans;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char dc[] = {'R','D','L','U'};
int n,m;

void dfs(int i,int j,int used,int cur){
    if(i<1||j<1||i>n||j>m) return;
    if(vis[i][j]) return;
    ans = max(ans,cur);
    for(int d=0;d<4;d++){
        int ch = dc[d];
        if(ch==g[i][j]){
            int nxt=cur+(!vis[i][j]);
            vis[i][j]=1;
            dfs(i+dx[d],j+dy[d],used,nxt);
            vis[i][j]=0;
        }
        else if(!used){
            if(vis[i][j]) continue;
            vis[i][j]=1;
            dfs(i+dx[d],j+dy[d],1,cur+1);
            vis[i][j]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int r,c;
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    dfs(r,c,0,1);
    cout << ans << '\n';
}
/*
觀察到可以對每個點預先計算接下來的路徑
但我不會處理環(
*/