#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int deg[N];
bool rem[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[b]++;
        deg[a]++;
    }
    priority_queue<pii,vector<pii>,greater<>> pq;
    for(int i=1;i<=n;i++) pq.push({deg[i],i});
    int ans = 0;
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(rem[u]) continue;
        ans = max(ans,d);
        rem[u]=1;
        for(int v:adj[u]){
            if(rem[v]) continue;
            pq.push({--deg[v],v});
        }
    }
    cout << ans << '\n';
}