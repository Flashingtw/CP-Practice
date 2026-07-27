#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int deg[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) q.push(i);
    }
    vector<int> ans(n+1);
    int cur=1;
    while(!q.empty()){
        if(q.size()>=2){
            cout << "No" << '\n';
            return 0;
        }
        int u = q.front();
        q.pop();
        ans[u]=cur++;
        for(int v:adj[u]){
            if(--deg[v]==0){
                q.push(v);
            }
        }
    }
    if(cur<n) cout << "No" << '\n';
    else{
        cout << "Yes" << '\n';
        for(int i=1;i<=n;i++){
            cout << ans[i] << ' ';
        }
    }
}