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
const int N = 505;
vi adj[N];
int vis[N],in[N],p[N];
int cnt;
vector<pii> edg;
int n,m;
bool dfs(int u,int par){
    vis[u]=1;
    in[u]=1;
    p[u] = par;
    for(int v:adj[u]){
        if(in[v]){
            int cur = u;
            edg.push_back({u,v});
            while(cur!=v){
                edg.push_back({p[cur],cur});
                cur = p[cur];
            }
            return 1;
        }
        else if(!vis[v]){
            if(dfs(v,u)) return 1;
        }
    }
    in[u]=0;
    return 0;
}
bool dfs(int u,pii del){
    vis[u]=1;
    in[u]=1;
    
    for(int v:adj[u]){
        if(make_pair(u,v)==del) continue;
        if(in[v]){
            return 1;
        }
        else if(!vis[v]){
            if(dfs(v,del)) return 1;
        }
    }
    in[u]=0;
    return 0;
}

void init(){
    rep(i,1,n+1){
        vis[i] = in[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    rep(i,1,n+1){
        if(vis[i]) continue;
        if(dfs(i,i)) break;
    }
    if(edg.empty()) {
        cout << "YES" << '\n';
        return 0;
    }
    for(pii e:edg){
        init();
        bool chk=1;
        rep(i,1,n+1){
            if(vis[i]) continue;
            if(dfs(i,e)) chk=0;
        }
        if(chk){
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
}
/*
1. 沒判本來就沒有環的時候
2. 他是有向圖 中間把它當無向圖
3. while沒寫好+找到環後要直接break
4. 不一定連通
*/