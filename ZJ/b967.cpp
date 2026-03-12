#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> adj[N];
int ans=0;

int dfs(int u,int p){
    int f=0,s=0;
    for(int v:adj[u]){
        if(v==p) continue;
        int d = dfs(v,u);
        if(d>f){
            s = f;
            f = d;
        }
        else if (d>s) s = d;
    }
    ans = max({ans,f+s});
    return f+1;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    cout << ans;
}