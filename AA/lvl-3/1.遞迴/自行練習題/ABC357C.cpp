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



char g[1000][1000];

void rec(int n,int p,int idx,int px,int py){
    if(idx==4){
        for(int i=0;i<p;i++){
            for(int j=0;j<p;j++){
                g[px+i][py+j]='.';
            }
        }
        return;
    }
    if(n==0){
        g[px][py]='#';
        return;
    }
    p/=3;
    for(int i=0;i<9;i++) {
        int nx = px+(i/3)*p;
        int ny = py+(i%3)*p;
        rec(n-1,p,i,nx,ny);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    int p=1;
    for(int i=0;i<n;i++){
        p*=3;
    }
    rec(n,p,0,0,0);
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cout << g[i][j];
        }
        cout << '\n';
    }
}