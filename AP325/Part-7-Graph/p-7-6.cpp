#include <bits/stdc++.h>
using namespace std;
#define oo 10000000
int main() {
    int n,m,source,goal;
    cin>>n>>m>>source>>goal;
    //Input num;
    vector<pair<int,int>> adj[n];
    vector<int> indeg(n,0);
    for (int i=0;i<m;i++) {
        int from,to,w;
        cin>>from>>to>>w;
        adj[from].push_back({to,w});
        ++indeg[to];
    }
    queue<int> q;
    vector<int> p(n,-oo),d(n,oo);
    p[source] = d[source] = 0;
    for (int i=0;i<n;i++) if (indeg[i]==0) q.push(i);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (auto e:adj[i]) {
            if (d[i]<oo) {
                d[e.first] = min(d[e.first],d[i]+e.second);
                p[e.first] = max(p[e.first],p[i]+e.second);
            }
            if (--indeg[e.first]==0) q.push(e.first);
        }
    }

    if (d[goal]==oo) {
        cout << "No path\nNo path";
        return 0 ;
    }
    cout << d[goal] << "\n" << p[goal];
}