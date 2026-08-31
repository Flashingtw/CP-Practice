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
int n,h,w;
int a[15],b[15];
int vis[15];
int used[15][15];

bool chk(int x,int y,int hei,int wid){
    int nx = hei+x;
    int ny = wid+y;
    if(nx>h||ny>w) return 0;
    for(int i=x;i<nx;i++){
        for(int j=y;j<ny;j++){
            if(used[i][j]) return 0;
        }
    }
    return 1;
}
void f(int x,int y,int hei,int wid,int v){
    int nx = hei+x;
    int ny = wid+y;
    for(int i=x;i<nx;i++){
        for(int j=y;j<ny;j++){
            used[i][j]+=v;
        }
    }
}
bool check=0;
void dfs(int x,int y){
    if(x==h){
        check=1;
        return;
    }
    if(y==w){
        dfs(x+1,0);
        return;
    }
    if(used[x][y]){
        dfs(x,y+1);
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(check) break;
        int hei = a[i];
        int wid = b[i];
        if(chk(x,y,hei,wid)){
            f(x,y,hei,wid,1);
            vis[i]=1;
            dfs(x,y+wid);
            vis[i]=0;
            f(x,y,hei,wid,-1);
        }
        if(chk(x,y,wid,hei)){
            f(x,y,wid,hei,1);
            vis[i]=1;
            dfs(x,y+hei);
            vis[i]=0;
            f(x,y,wid,hei,-1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>h>>w;
    rep(i,0,n){
        cin>>a[i]>>b[i];
    }
    dfs(0,0);
    cout << (check?"Yes":"No") << '\n';
}