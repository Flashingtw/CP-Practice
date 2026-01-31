#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int n,q;
int in[N],out[N];
int timer=0;
long long bit[N];
int val[N];

void dfs(int u,int p) {
    in[u]=++timer;
    for (int v: adj[u]) {
        if (v!=p) dfs(v,u);
    }
    out[u] = timer;
}
void update(int idx, int val) {
    for (;idx<=n;idx+= idx&-idx) {
        bit[idx] += val;
    }
}
long long query(int idx) {
    long long sum=0;
    for (;idx>0;idx-= idx&-idx) {
        sum+=bit[idx];
    }
    return sum;
}
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>val[i];
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) {
        update(in[i],val[i]);
    }
    while (q--) {
        int type;
        cin>>type;
        if (type==1) {
            int node,num;
            cin>>node>>num;
            int d = num-val[node];
            update(in[node],d);
            val[node] = num;
        }
        else {
            int node;
            cin>>node;
            cout << query(out[node])-query(in[node]-1) << "\n";
        }
    }
}