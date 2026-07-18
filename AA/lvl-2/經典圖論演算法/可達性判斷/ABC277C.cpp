#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
map<int,vector<int>> adj;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> vis;
    queue<int> q;
    q.push(1);
    int mx=1;
    vis.insert(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        mx = max(mx,u);
        for(int v:adj[u]){
            if(vis.find(v)!=vis.end()) continue;
            q.push(v);
            vis.insert(v);
        }
    }
    cout << mx << '\n';
}