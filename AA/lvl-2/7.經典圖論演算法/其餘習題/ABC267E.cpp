#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
ll a[N];
int n,m;

struct state{
    int v;
    ll c;
    bool operator<(const state &oth) const{
        return c>oth.c;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<state> pq;
    vector<ll> c(n+1);
    for(int i=1;i<=n;i++){
        ll t=0;
        for(int v:adj[i]){
            t+=a[v];
        }
        pq.push({i,t});
        c[i]=t;
    }
    ll ans=0;
    vector<int> del(n+1);
    while(!pq.empty()){
        auto [u,cos] = pq.top();
        pq.pop();
        if(c[u]!=cos||del[u]) continue;
        del[u]=1;
        ans = max(ans,cos);
        for(int v:adj[u]){
            if(del[v]) continue;
            c[v]-=a[u];
            pq.push({v,c[v]});
        }
    }
    cout << ans << '\n';
}
//這題二分應該也行