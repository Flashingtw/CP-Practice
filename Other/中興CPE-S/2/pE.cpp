#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 100005;
vector<int> adj[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    int nd=1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pii> ans;
    vector<int> vis(n+1);
    vector<vector<int>> cps;
    int idx=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        cps.push_back(vector<int>());
        queue<int> q;
        q.push(i);
        vis[i]=1;
        int cnt = 1;
        bool chk=1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cps[idx].push_back(u);
            for(int v:adj[u]){
                if(vis[v]) continue;
                q.push(v);
                vis[v]=1;
                cnt++;
            }
        }
        idx++;
    }
    if(cps.size()>=3){
        for(int i=0;i<idx-1;i++){
            ans.push_back({cps[i][0],cps[i+1][0]});
        }
        ans.push_back({cps[idx-1][0],cps[0][0]});
    }
    if(cps.size()==2){
        if(cps[0].size()<cps[1].size()) swap(cps[0],cps[1]);
        ans.push_back({cps[0][0],cps[1][0]});
        ans.push_back({cps[0][1],cps[1][0]});
     }
    if(cps.size()==1){
        vector<int> a;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==1) a.push_back(i);
        }
        ans.push_back({a[0],a[1]});
    }
    cout << ans.size() << '\n';
    for(auto [a,b]:ans) cout << a << ' ' << b << '\n';
}