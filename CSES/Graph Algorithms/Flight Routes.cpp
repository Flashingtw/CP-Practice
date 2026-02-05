#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long ll;
typedef pair<ll,int> pli;
vector<pli> adj[N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    vector<vector<ll>> dist(n+1);
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,u] = pq.top();pq.pop();
        if(dist[u].size()>=k) continue;
        else dist[u].push_back(d);
        for(auto [c,v]:adj[u]){
            pq.push({d+c,v});
        }
    }
    for(ll i:dist[n]) cout << i << " ";
}