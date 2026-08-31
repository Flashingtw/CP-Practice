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
string g[1500];
string ans;
void rec(int n,int x,int y){
    bool chk=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(g[i][j]!=g[x][y]){
                chk=1;
                break;
            }
        }
    }
    if(chk){
        ans.push_back('2');
        int nx=n/2;
        rec(nx,x,y);
        rec(nx,x,y+nx);
        rec(nx,x+nx,y);
        rec(nx,x+nx,y+nx);
    }
    else{
        ans.push_back(g[x][y]);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>g[i];
    rec(n,0,0);
    cout << ans << '\n';
}