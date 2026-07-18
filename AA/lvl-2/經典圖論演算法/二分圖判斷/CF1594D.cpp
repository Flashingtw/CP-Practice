#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct edg{
    int v;
    int t;
};

int bfs(vector<int> &clr,int i,vector<vector<edg>> &adj){
    queue<int> q;
    q.push(i);
    int cnt=0,total=0;
    bool chk=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        total++;
        if(clr[u]==2) cnt++;
        for(auto [v,t]:adj[u]){
            int nxt=0;
            if(clr[u]==1) nxt=t;
            else nxt=3-t;
            if(clr[v]>0){
                if(clr[v]!=nxt) return -1;   
            }
            if(clr[v]>0) continue;
            q.push(v);
            clr[v]=nxt;
        }
    }
    return max(total-cnt,cnt);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<edg>> adj(n+1);
    for(int i=0;i<m;i++){
        string s;
        int a,b;
        cin>>a>>b>>s;
        adj[a].push_back({b,(s[0]=='c'?1:2)});
        adj[b].push_back({a,(s[0]=='c'?1:2)});
        // a->b (2) == b->a (1)
    }
    //直接假設 平民跟狼可以反轉
    vector<int> clr(n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(clr[i]) continue;
        clr[i]=1;
        int a = bfs(clr,i,adj);
        if(a==-1) {
            cout << -1 << '\n';
            return;
        }
        else ans+=a;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}