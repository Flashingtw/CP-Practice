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
const int N = 2e6+5;
const int K = 1e6+5;
ll cnt[N];
vpii adj[N];
ll ans=0;
void dfs(int u,ll cur){
    ans^=cur;
    for(auto [v,t]:adj[u]){
        int i=abs(t);
        ll tmp = cnt[i]-(t<0);
        if(t<0) cnt[i]--;
        else cnt[i]++;
        dfs(v,cur+t*(tmp*2+1));
        if(t<0) cnt[i]++;
        else cnt[i]--;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    rep(i,0,n){
        int a;
        cin>>a;
        cnt[a]++;
    }
    ll cur=0;
    rep(i,1,2e6+1) cur+=i*cnt[i]*cnt[i]; 
    
    rep(i,1,k+1){
        int s,t;
        cin>>s>>t;
        adj[s].push_back({i,t});
    }
    dfs(0,cur);
    cout << ans << '\n';
}
/*
版本樹的概念
*/