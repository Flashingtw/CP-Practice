#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> col(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!col[i]){
            queue<int> q;
            q.push(i);
            col[i]=1;
            int cnt1=0,cnt2=0;
            bool chk=0;
            while(!q.empty()){
                int u = q.front();
                if(col[u]==1) cnt1++;
                else cnt2++;
                q.pop();
                for(int v:adj[u]){
                    if(col[v]==0){
                        q.push(v);
                        col[v]= 3-col[u];
                    }
                    else if(col[v]==col[u]){
                        chk=1;
                    }
                }
            }
            if(!chk) ans+=max(cnt1,cnt2);
        }
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}