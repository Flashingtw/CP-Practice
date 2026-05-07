#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int deg[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }
    while (!q.empty()){
        if(q.size()>1){
            cout << 1 << '\n';
            return 0;
        }
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(--deg[v]==0){
                q.push(v);
            }
        }
    }
    cout << 0 << '\n';
}