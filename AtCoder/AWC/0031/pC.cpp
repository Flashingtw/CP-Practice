#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
vector<int> adj[1505];
ll n,d,s,t;
ll dist(pii a,pii b){
    auto [x1,y1]=a;
    auto [x2,y2]=b;
    ll x = x1-x2;
    ll y = y1-y2;
    return (x*x)+(y*y);
}
int main(){
    cin>>n>>d>>s>>t;
    vector<pii> pos(n+1);
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        pos[i]={x,y};
        for(int j=1;j<i;j++){
            if(dist(pos[i],pos[j])<=d*d){
               adj[i].push_back(j);
               adj[j].push_back(i); 
            }
        }
    }
    vector<int> dis(n+1,INF);
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(dis[v]!=INF) continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    if(dis[t]==INF) cout << -1;
    else cout << dis[t];
}