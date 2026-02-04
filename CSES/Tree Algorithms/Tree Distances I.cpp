#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int n;
void dfs(int u,int p,int d,vector<int> &dis) {
    dis[u]=d;
    for (int v:adj[u]) {
        if (v==p) continue;
        dfs(v,u,d+1,dis);
    }
}
int Get(vector<int> &dis) {
    int r=-1,node=-1;
    for (int i=1;i<=n;i++) {
        if (dis[i]>r) {
            r=dis[i];
            node=i;
        }
    }
    return node;
}
int main() {
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> arr(n+1);
    vector<int> A(n+1);
    vector<int> B(n+1);
    dfs(1,0,0,arr);

    int node_a = Get(arr);
    dfs(node_a,0,0,A);

    int node_b = Get(A);
    dfs(node_b,0,0,B);

    for (int i=1;i<=n;i++) {
        cout << max(A[i],B[i]) << " ";
    }
}