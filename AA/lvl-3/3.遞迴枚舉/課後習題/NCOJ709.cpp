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
int n,m;
int col[10];
int used[2][2][20];//[皇后/城堡][右上/右下][第幾格]
ll ans;
void dfs(int idx,int q,int c){
    if(idx==n+m){
        ans++;
        return;
    }
    for(int i=0;i<n+m;i++){
        if(q<n&&!(col[i]||used[0][0][idx+i]||used[0][1][idx-i+n+m]||used[1][0][idx+i]||used[1][1][idx-i+n+m])){
            col[i]=used[1][0][idx+i]=used[1][1][idx-i+n+m]=1;
            dfs(idx+1,q+1,c);
            col[i]=used[1][0][idx+i]=used[1][1][idx-i+n+m]=0;
        }
        if(c<m&&!(col[i]||used[1][0][idx+i]||used[1][1][idx-i+n+m])){
            col[i]=1;
            used[0][0][idx+i]++;
            used[0][1][idx-i+n+m]++;
            dfs(idx+1,q,c+1);
            used[0][0][idx+i]--;
            used[0][1][idx-i+n+m]--;
            col[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    dfs(0,0,0);
    cout << ans << '\n';
}