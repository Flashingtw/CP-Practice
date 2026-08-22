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

pii dd[4][4] =
{
    {{0,0},{1,0},{1,1},{0,1}},
    {{0,0},{0,1},{1,1},{1,0}},
    {{1,1},{1,0},{0,0},{0,1}},
    {{1,1},{0,1},{0,0},{1,0}}
};

int d[4][4] =
{
    {1,0,0,2},
    {0,1,1,3},
    {3,2,2,0},
    {2,3,3,1},
};
int g[3000][3000];
int cnt;
void rec(int n,int dir,int p,int x,int y){
    if(n==0){
        g[x][y]=cnt++;
        return;
    }
    p/=2;
    for(int i=0;i<4;i++){
        auto [dx,dy] = dd[dir][i];
        int nx = x+dx*p;
        int ny = y+dy*p;
        rec(n-1,d[dir][i],p,nx,ny);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    int p = 1<<n;
    rec(n,0,p,0,0);
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}
/*
難,再複習
*/