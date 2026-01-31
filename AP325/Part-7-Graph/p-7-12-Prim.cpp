#include <bits/stdc++.h>
using namespace std;
#define N 10005
          //num,cost
vector<pair<int,int>> adj[N]; // Linked list
int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    priority_queue<pair<int,int>> pq;
    int total_cost =0;
    bool visited[N] = {false};
    int cnt=0;
    pq.push({0,0});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        if (visited[u]) continue;
        visited[u] = true;
        total_cost-=p.first;
        cnt++;
        for (auto v : adj[u]) {
            pq.push({-v.second,v.first});
        }
    }
    cout << (cnt!=n?-1:total_cost);
}