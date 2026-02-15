#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 1e9+9;
vector<int> adj[N];
int deg[N],p[N],d[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    vector<int> topo;
    queue<int> q;
    for(int i=1;i<=n;i++){
        d[i]=-INF;
        p[i]=-1;
        if(deg[i]==0) {
            q.push(i);
        }
    }
    d[1]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v:adj[u]){
            deg[v]--;
            if(d[v]<d[u]+1&&d[u]!=-INF){
                d[v]=d[u]+1;
                p[v]=u;
            }
            if(deg[v]==0) q.push(v);
        }
    }
    if(d[n]==-INF){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    int cur=n;
    vector<int> ans;
    while(cur!=-1){
        ans.push_back(cur);
        cur = p[cur];
    }
    cout << ans.size() << "\n";
    for(int i = ans.size()-1;i>=0;i--) cout << ans[i] << " ";
}