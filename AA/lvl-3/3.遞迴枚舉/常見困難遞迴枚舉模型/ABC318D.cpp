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
ll w[20][20];
int vis[20];
ll ans;
void dfs(int idx,ll cur,bool chk){
    if(idx==n){//停止條件
        ans = max(ans,cur); 
        return;
    }
    if(vis[idx]){
        dfs(idx+1,cur,chk);//如果已經被選過
        return;
    }
    if(chk) dfs(idx+1,cur,0);//讓他單獨
    
    for(int i=idx+1;i<=n;i++){//枚舉點->下個點
        if(vis[i]) continue;
        vis[i]=1;
        dfs(idx+1,cur+w[idx][i],chk);
        vis[i]=0;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    rep(i,1,n+1){
        rep(j,i+1,n+1){
            ll x;
            cin>>x;
            w[i][j] = w[j][i] = x;
        }
    }
    dfs(1,0,n&1);//奇數有一個會單獨
    cout << ans << '\n';
}