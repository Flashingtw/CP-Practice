#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long NINF = -1e18;
struct EDGE {
    int u,v;
    long long w;
};
int main() {
    int n,m;
    cin>>n>>m;
    vector<EDGE> edge;
    for (int i=0;i<m;i++) {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        edge.push_back({u,v,-w});
    }
    vector<long long> dist(n + 1, INF);//抵達i點的最小成本
    dist[1] = 0;//起點開始
    for (int i=1;i<=n-1;i++) {
        for (EDGE &e : edge) {
            if (dist[e.u]==INF) continue;
            if (dist[e.u]+e.w<dist[e.v]) {
                dist[e.v] = dist[e.u]+e.w;
            }
        }
    }
    //check cycle
    for (int i=1;i<=n;i++) {
        for (EDGE &e : edge) {
            if (dist[e.u]==INF) continue;
            if (dist[e.u]==NINF) {
                dist[e.v] = NINF;
            }
            if (dist[e.u]+e.w<dist[e.v]) {//Positive Cycle
                dist[e.v] = NINF;
            }
        }
    }
    cout << (dist[n]==NINF?-1:-dist[n]);
}