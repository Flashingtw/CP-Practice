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
const int mod = 1e9+7;

int vis[15];
vi adj[15];
ll cnt[15];
/*
寫法1 紀錄全部環的長度
最後統計時因為環上每個點會計算左右兩邊 所以要/i/2
*/
//void dfs(int st,int u,int len){
//    vis[u]=1;
//    for(int v:adj[u]){
//        if(st==v) cnt[len]++;
//        if(vis[v]) continue;
//        dfs(st,v,len+1);
//    }
//    vis[u]=0;
//}
/*
寫法2 讓每個點只負責較往點數較大的環走, 也就是少走/2遍..?
*/
int ans=0;
void dfs(int st,int u){
    vis[u] = 1;
    for(int v:adj[u]){
        if(v==st) ans++;
        if(vis[v]||v<st) continue;
        dfs(st,v);
    }
    vis[u] = 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*
    寫法1
    rep(i,1,n+1) dfs(i,i,1);
    ll ans=0;
    rep(i,3,n+1){
        ans= (ans+(cnt[i]/i/2))%mod;
    }
    cout << ans << '\n';
    */

    rep(i,1,n+1) dfs(i,i);
    cout << (ans-m)/2 << '\n';
}