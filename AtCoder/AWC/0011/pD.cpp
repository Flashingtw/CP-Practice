#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
vector<int> adj[N];
ll val[N],p[N],ans[N];
void dfs(int u,ll num){
    ans[u] = num;
    for(int v :adj[u]){
        dfs(v,num+val[v]);
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=2;i<=n;i++){
        int pa;
        cin>>pa;
        adj[pa].push_back(i);
    }
    dfs(1,val[1]);
    while(q--){
        int x;
        cin>>x;
        cout << ans[x] << "\n";
    }
}