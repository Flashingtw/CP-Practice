#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 405;
int n,m;
struct edg{
    int t,id;
};
vector<edg> adj[N];
vector<edg> rev[N];

int bfs(int idx){
    vector<int> dis(n+1,1e9);
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==n){
            return dis[u];
        }
        for(auto [v,id]:adj[u]){
            if(dis[v]!=1e9||id==idx) continue;
            q.push(v);
            dis[v]=dis[u]+1;
        }
    }
    return -1;
}
set<int> s;
int bfs_f(){
    vector<int> dis(n+1,1e9);
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==n){
            break;
        }
        for(auto [v,id]:adj[u]){
            if(dis[v]!=1e9) continue;
            q.push(v);
            dis[v]=dis[u]+1;
        }
    }
    int cur=n;
    int need = dis[n];
    if(need==-1) return -1;
    while(cur!=1){
        int nxt=-1;
        for(auto [v,id]:rev[cur]){
            if(dis[v]==need-1){
                need--;
                nxt=v;
                s.insert(id);
                break;
            }
        }
        if(nxt==-1) return -1;
        cur=nxt;
    }
    return (dis[n]==1e9?-1:dis[n]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        adj[s].push_back({t,i});
        rev[t].push_back({s,i});
    }
    int ans = bfs_f();
    for(int i=0;i<m;i++){
        if(s.find(i)!=s.end()){
            cout << bfs(i) << '\n';
        }
        else cout << ans << '\n';
    }
}