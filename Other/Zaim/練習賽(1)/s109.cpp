#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
vector<int> adj[N];
int col[N];
bitset<1005> bt;
bool dfs(int u,int p,int target){
    bt.flip(col[u]);
    if(u==target) return true;
    for(int v:adj[u]){
        if(v==p) continue;
        if(dfs(v,u,target)) return true;
    }
    bt.flip(col[u]);
    return false;
}

int main(){
    int n,c,q;
    cin>>n>>c>>q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>col[i];
    while(q--){
        char type;
        cin>>type;
        if(type=='Q'){
            int u,v;
            cin>>u>>v;
            dfs(u,0,v);
            cout << bt.count() << '\n';
            bt.reset();
        }
        else{
            int u,c;
            cin>>u>>c;
            col[u]=c;
        }
    }
}