#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool in_stack[N],vis[N];
int p[N];
vector<int> adj[N];
bool fnd;
int c_s,c_e;
void dfs(int u){
    in_stack[u]=true;
    vis[u]= true;
    for(int v:adj[u]){
        if(in_stack[v]){
            fnd=true;
            c_s=u,c_e=v;
        }
        else if (!vis[v]){
            p[v]=u;
            dfs(v);
        }
    }
    in_stack[u]=false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!fnd&&!vis[i]) dfs(i);
        if(fnd) break;
    }
    if(fnd){
        vector<int> cyc;
        int cur = c_s;
        cyc.push_back(c_s);
        while(cur!=c_e){
            cur = p[cur];
            cyc.push_back(cur);
        }
        cyc.push_back(c_s);
        cout << cyc.size() << "\n";
        reverse(cyc.begin(),cyc.end());
        for(int i:cyc) cout << i << " ";
    }
    else{
        cout << "IMPOSSIBLE";
    }
}