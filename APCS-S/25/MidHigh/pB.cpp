#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
vector<int> adj[N];
int w[N];
vector<pair<ll,int>> C;
void dfs(int u,int p,ll sum,int d){
    C.push_back({sum,d});
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u,sum+w[v],d+1);
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,w[i],1);
    }
    sort(C.begin(),C.end());
    vector<pair<ll,int>> best;
    for(auto &p:C){
        if(!best.empty()&&best.back().first == p.first) best.back().second=min(best.back().second,p.second);
        else best.push_back(p);
    }
    for(int i=best.size()-2;i>=0;i--){
        best[i].second = min(best[i].second,best[i+1].second);
    }
    while(q--){
        ll k;
        cin>>k;
        auto it=lower_bound(best.begin(),best.end(),make_pair(k,-1));
        if(it==best.end()) cout << "Shinra Tensei" << '\n';
        else cout << (it->second) << '\n';
    }
}