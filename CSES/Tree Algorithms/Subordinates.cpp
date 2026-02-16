#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int sz[N];

int dfs(int u){
    sz[u]=0;
    for(int v:adj[u]){
        sz[u]+=dfs(v);
    }
    return sz[u]+1;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int num;
        cin>>num;
        adj[num].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout << sz[i] << ' ';
}