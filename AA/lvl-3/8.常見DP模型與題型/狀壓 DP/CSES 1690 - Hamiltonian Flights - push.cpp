#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define EB emplace_back
#define f first
#define s second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define RREP(i,a,b) for(int i=(a);i>=(b);--i)
#define EACH(x,a) for(auto &x : a)

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

int dp[1<<20][20];
int n,m;
vi adj[25];

void upd(int &a,ll b){
    a = (a+b)%mod;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    REP(i,0,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
    }
    dp[1][0]=1;
    for(int st=1;st<(1<<n);st+=2){
        for(int u=0;u<n-1;u++){
            if(!((st>>u)&1)) continue;
            for(int v:adj[u]){
                if(!((st>>v)&1)){
                    int nxt = st|(1<<v);
                    if(v==n-1&&nxt!=(1<<n)-1) continue;
                    upd(dp[nxt][v],dp[st][u]);
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << '\n';
}
/*
複習
剪枝、好好實作
*/