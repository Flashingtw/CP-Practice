#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
vector<int> adj[2*N];
ll ans[N];
void dfs(int u,int d){
    if(adj[u].empty()){
        ans[u]=d;
        return;
    }
    for(int v:adj[u]){
        dfs(v,d+1);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
    }
    int cnt=n;
    while(pq.size()>1){
        pii x = pq.top();
        pq.pop();
        pii y = pq.top();
        pq.pop();
        adj[cnt].push_back(x.second);
        adj[cnt].push_back(y.second);
        pq.push({x.first+y.first,cnt++});
    }
    dfs(cnt-1,0);
    ll t=0;
    for(int i=0;i<n;i++){
        t+= ans[i]*a[i];
    }
    cout << (n>1?t:a[0]) << '\n';
}