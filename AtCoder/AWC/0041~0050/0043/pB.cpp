#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
pii r[N];
int chk[N],ans[N];
vector<int> adj[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>r[i].first;
        r[i].second=i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(r+1,r+n+1,greater());
    for(int i=1;i<=n;i++){
        int u = r[i].second;
        if(chk[u]) continue;
        int mn = 1e9;
        for(int v:adj[u]){
            if(chk[v]) continue;
            if(v<mn) mn=v;
        }
        if(mn!=1e9){
            ans[u] = mn;
            ans[mn]=u;
            chk[mn]=1;
            chk[u]=1;
        }
    }
    cout << ans[1];
}