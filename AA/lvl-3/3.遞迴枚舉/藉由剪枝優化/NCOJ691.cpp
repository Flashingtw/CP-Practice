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
int n;
int vis[3][25];

int g[15][15];

void dfs(int idx){
    if(idx==n){
        rep(i,0,n){
            rep(j,0,n){
                cout << (g[i][j]?'Q':'*');
            }
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    rep(i,0,n){
        if(vis[0][i]) continue;
        if(vis[1][idx+i]) continue;
        if(vis[2][idx-i+n]) continue;
        g[idx][i] = vis[0][i] = vis[1][idx+i] = vis[2][idx-i+n] = 1;
        dfs(idx+1);
        g[idx][i] = vis[0][i] = vis[1][idx+i] = vis[2][idx-i+n] = 0;
    }
}
//y=x+k -> y-x = k
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    dfs(0);
}