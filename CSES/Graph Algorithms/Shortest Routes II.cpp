#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
    for (int i=1;i<=n;i++) dist[i][i] =0;
    for (int i=0;i<m;i++) {
        int a,b;
        long long w;
        cin>>a>>b>>w;
        dist[a][b] = min(dist[a][b],w);
        dist[b][a] = min(dist[b][a],w);
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (dist[i][k]!=INF&&dist[k][j]!=INF) {
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    while (q--) {
        int i,j;
        cin>>i>>j;
        cout <<(dist[i][j]==INF?-1:dist[i][j]) << "\n";
    }
}