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
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int h,w;
ll cnt=0;
int vis[35][35];
void dfs(int x,int y,vpii &ans){
    if(x<1||y<1||x>h||y>w) return;
    if(x==h&&y==w){
        int sz=ans.size();
        cout << '(' << ans[0].F << ',' << ans[0].S << ')';
        for(int i=1;i<sz;i++) cout << '-' << '(' << ans[i].F << ',' << ans[i].S << ')';
        cout << '\n';
        cnt++;
        return;
    }
    rep(d,0,4){
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(vis[nx][ny]) continue;
        ans.push_back({nx,ny});
        vis[nx][ny]=1;
        dfs(nx,ny,ans);
        ans.pop_back();
        vis[nx][ny]=0;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>h>>w;
    vpii ans = {{1,1}};
    vis[1][1]=1;
    dfs(1,1,ans);
    cout << "total path num: " << cnt << '\n';
}