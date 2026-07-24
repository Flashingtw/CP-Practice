#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll a[N];
vector<int> adj[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int u=1;u<=n;u++){
        cin>>a[u];
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            int v;
            cin>>v;
            adj[u].push_back(v);
        }
    }
    vector<int> vis(n+1);
    queue<int> q;
    q.push(n);
    vis[n]=1;
    ll ans = a[n];
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]) continue;
            ans+=a[v];
            q.push(v);
            vis[v]=1;
        }
    }
    cout << ans << '\n';
}