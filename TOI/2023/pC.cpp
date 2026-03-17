#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const int INF = 1e9;
vector<int> adj[N];
ll a[N];
ll ans = -1e18;
bool in[N];
ll dfs(int u,int p){
    ll fir=0,sec=0;
    for(int v:adj[u]){
        if(v==p||in[v]) continue;
        ll val = dfs(v,u);
        if(val>=fir) {
            sec=fir;
            fir=val;
        }
        else if(val>sec) sec=val;
    }
    ans = max(ans,a[u]+fir+sec);
    return a[u]+fir;
}

int p[N];
bool vis[N];
vector<int> cycle;
bool fnd;
void dfs_cycle(int u,int pa){
    if(fnd) return;
    p[u]=pa;
    vis[u]=1;
    for(int v:adj[u]){
        if(v==pa) continue;
        if(vis[v]){
            // v is cycle first
            int cur=u;
            while(cur!=p[v]){
                in[cur]=1;
                cycle.push_back(cur);
                cur = p[cur];
            }
            fnd=1;
            return;
        }
        dfs_cycle(v,u);
        if(fnd) return;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs_cycle(1,0);
    if(n-1==m) dfs(1,0);
    else{
        vector<ll> E_arr, V_arr;
        int L = cycle.size();
        for (int i : cycle) {
            E_arr.push_back(dfs(i, 0));
            V_arr.push_back(a[i]);
        }
        for (int i = 0; i < L; i++) {
            E_arr.push_back(E_arr[i]);
            V_arr.push_back(V_arr[i]);
        }
        vector<ll> prefix(2*L);
        prefix[0] = V_arr[0];
        for (int i=1;i<2*L; i++) {
            prefix[i] = prefix[i-1] + V_arr[i];
        }
        deque<int> dq;
        for (int i=0;i<2*L-1;i++) {
            while (!dq.empty() && i - dq.front() >= L) dq.pop_front();
            if (!dq.empty()) ans = max(ans, E_arr[i] + E_arr[dq.front()] + prefix[i-1] - prefix[dq.front()]);
            ll val_i = E_arr[i] - prefix[i];
            while (!dq.empty() && (E_arr[dq.back()] - prefix[dq.back()]) <= val_i) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    cout << ans;
}