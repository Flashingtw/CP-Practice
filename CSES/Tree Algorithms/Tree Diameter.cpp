#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int ans=0;
int dfs(int u,int p) {
    int max_1=0,max_2=0;
    for (int v : adj[u]) {
        if (v==p) continue;
        int len = dfs(v,u)+1;

        if (len>max_1) swap(len,max_1);
        if (len>max_2) swap(len,max_2);
    }
    ans = max(ans,max_1+max_2);
    return max_1;
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << ans;
}