#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n+1,-1);
    queue<int> q;
    q.push(1);
    p[1]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(p[v]==-1){
                q.push(v);
                p[v] = u;
            }
        }
    }
    if(p[n]==-1){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int> res;
        int cur = n;
        while(cur!=0){
            res.push_back(cur);
            cur = p[cur];
        }
        cout << res.size() << "\n";
        for(int i=res.size()-1;i>=0;i--){
            cout << res[i] << " ";
        }
    }
}