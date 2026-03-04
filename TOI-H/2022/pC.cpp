#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 100005;
int n,k;
int w[N];
vector<pii> adj[N];
ll ans;
pii dfs(int u,int p){
    int c=0,num=0;
    for(auto [v,cost]:adj[u]){
        if(v==p) continue;
        auto [cnt,val] = dfs(v,u);
        c+= cnt; num+=val;
        ans+= abs(val-cnt*k)*cost;
    }
    return {c+1,num+w[u]};
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dfs(1,0);
    cout << ans;
}