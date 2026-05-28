#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 100005;
int clr[N];
vector<int> adj[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    int nd=1;
    for(int i=2;i<=n;i++) {
        cin>>clr[i];
        if(clr[i]) nd++;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    int cnt=1;
    vector<int> vis(n+1);
    vis[1]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(vis[v]||!clr[v]) continue;
            q.push(v);
            vis[v]=1;
            cnt++;
        }
    }
    if(cnt!=nd) cout << "Report the advertiser!!!" << '\n';
    else cout << "This level is fair, no need to report it." << '\n';
}