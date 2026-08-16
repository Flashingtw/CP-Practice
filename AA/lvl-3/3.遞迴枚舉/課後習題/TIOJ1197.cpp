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
vi adj[12];
int room[12];
int n,m;
ll ans;
void dfs(int idx,int can){
    if(idx>m){
        ans++;
        return;
    }
    for(int i=1;i<=can;i++){
        bool chk=1;
        for(int v:adj[idx]){
            if(v>idx) break;
            if(room[v]==i){
                chk=0;
                break;
            }
        }
        if(chk){
            room[idx]=i;
            dfs(idx+1,can);
            room[idx]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>m>>n;
    int a,b;
    while(cin>>a>>b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i,1,m+1) sort(all(adj[i]));
    int mn=1e9;
    rep(i,1,n+1){
        ans = 0;
        dfs(1,i);
        if(ans){
            mn = min(mn,i);
        }
    }
    cout << ans << '\n';
    if(ans) cout << mn << '\n'; 
    else{
        rep(i,n+1,11){
            dfs(1,i);
            if(ans){
                cout << i << '\n';
                return 0;
            }
        }
    }
}
/*
小範圍 → 枚舉
解空間描述
DFS 寫法
局部合法性判斷一開始不確定，後來成功補上
*/