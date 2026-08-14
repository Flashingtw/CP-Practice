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
int vis[20][20];
int h,w,a,b;
ll ans;
/*
左->右 上->下 枚舉3種可能, 蓋1x1,1x2,2x1
*/
void dfs(int i,int j,int ua,int ub){
    if(j==w+1){
        i++;j=1;
    }
    if(i==h+1){
        ans++;
        return;
    }
    if(vis[i][j]) {
        dfs(i,j+1,ua,ub);
        return;
    }
    if(ua<a){
        if(j<w&&!vis[i][j+1]){
            vis[i][j]=vis[i][j+1]=1;
            dfs(i,j+2,ua+1,ub);
            vis[i][j]=vis[i][j+1]=0;
        }
        if(i<h&&!vis[i+1][j]){
            vis[i][j]=vis[i+1][j]=1;
            dfs(i,j+1,ua+1,ub);
            vis[i][j]=vis[i+1][j]=0;
        }
    }
    if(ub<b){
        vis[i][j]=1;
        dfs(i,j+1,ua,ub+1);
        vis[i][j]=0;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>h>>w>>a>>b;
    dfs(1,1,0,0);
    cout << ans << '\n';
}