#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct G{
    int sz;
    vector<vector<int>> adj;
    vector<int> vis;
    G(int _sz) : sz(_sz+1),adj(_sz+1),vis(_sz+1) {};
    int bfs(int idx){
        queue<int> q;
        q.push(idx);
        vis[idx]=1;
        int i = 0;
        while(!q.empty()){
            i++;
            int u = q.front();
            q.pop();
            for(int i:adj[u]){
                if(vis[i]) continue;
                q.push(i);
                vis[i]=1;
            }
        }
        return i;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    G ga(n),gb(n);
    for(int i=1;i<=n;i++){
        ga.adj[i].push_back(a[i]);
        gb.adj[i].push_back(b[i]);
    }
    set<ll> sa,sb;
    for(int i=1;i<=n;i++){
        if(!ga.vis[i]){
            sa.insert(ga.bfs(i));
        }
        if(!gb.vis[i]){
            sb.insert(gb.bfs(i));
        }
    }
    ll mx=0,ans=-1;
    for(ll i:sa){    
        ll mn=9e18;
        for(ll j:sb){
            mn = min(mn,i/gcd(i,j)*j);
        }
        if(mn>mx){
            mx = mn;
            ans = mn;
        }
    }
    cout << ans << '\n';
}