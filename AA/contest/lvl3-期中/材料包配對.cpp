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

int g[25][25];
int rev[25][25];
int used[25][25];
int m,n;
int ans;

void rec(int d,int idx){
    if(d==m){
        ans++;
        return;
    }
    if(idx==n){
        rec(d+1,0);
        return;
    }

    if(used[d][idx]){
        rec(d,idx+1);
        return;
    }

    used[d][idx]=1;
    if(idx<n-1&&!used[d][idx+1]){
        used[d][idx+1] = 1;
        rec(d,idx+2);
        used[d][idx+1] = 0;
    }
    if(d<m-1){
        used[d+1][rev[d+1][g[d][idx]]] = 1;
        rec(d,idx+1);
        used[d+1][rev[d+1][g[d][idx]]] = 0;
    }
    used[d][idx]=0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            rev[i][g[i][j]] = j;
        }
    }
    rec(0,0);
    cout << ans << '\n';
}
/*
今天這格的人 明天坐在哪 沒弄清楚
*/