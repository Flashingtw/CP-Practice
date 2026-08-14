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

vector<pic> adj[1005];

int vis[1005][1005];

struct state{
    int s,t,d;
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        char c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    queue<state> q;
    vis[1][n]=1;
    q.push({1,n,0});
    int ans=1e9;
    while(!q.empty()){
        auto [s,t,d] = q.front();
        q.pop();
        if(s==t){
            ans = min(ans,d*2);
        }
        for(auto [a,c1]:adj[s]){
            if(a==t){
                ans = min(ans,d*2+1);
            }
            for(auto [b,c2]:adj[t]){
                if(c1!=c2||vis[a][b]) continue;
                vis[a][b] = 1;
                q.push({a,b,d+1});
            }
        }
    }
    cout << (ans==1e9?-1:ans) << '\n';
}