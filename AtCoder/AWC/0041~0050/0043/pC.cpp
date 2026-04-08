#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
ll w[N];
ll ans[N];

ll dfs(int u){
    ll sum=w[u];
    ll mx=0,mn=1e18;
    int sz = adj[u].size();
    for(int v:adj[u]){
        ll d = dfs(v);
        mx = max(mx,d);
        mn = min(mn,d);
        sum+=d;
    }
    if(sz<=1) ans[u]=0;
    else ans[u] = mx-mn;
    return sum;
}

int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    dfs(1);
    ll total=0;
    for(int i=1;i<=n;i++){
        total=max(total,ans[i]);
    }
    cout << total;
}