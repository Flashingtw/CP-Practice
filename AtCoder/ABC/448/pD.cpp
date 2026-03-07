#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int val[N];
bool ans[N];
set<int> s;
void dfs(int u,int p,bool chk){
    if(chk) ans[u]=1;
    else{
        if(s.count(val[u])){
            ans[u]=1;
            chk=1;
        }
        else{
            s.insert(val[u]);
        }
    }
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u,chk);
    }
    if(!chk){
        s.erase(val[u]);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        cout << (ans[i]?"Yes":"No") << '\n';
    }
}