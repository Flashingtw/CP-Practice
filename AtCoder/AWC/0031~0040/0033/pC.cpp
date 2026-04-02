#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<int> adj[N];
int cnt[N],chk[N];
int main(){
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    queue<int> q;
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        q.push(a);
        chk[a]=1;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            cnt[v]++;
            if(cnt[v]>=t&&(!chk[v])){
                q.push(v);
                chk[v]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(chk[i]) ans++;
    }
    cout << ans;
}