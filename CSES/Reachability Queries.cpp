#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
bitset<N> dp[N];
vector<int> adj[N];
vector<int> dag_adj[N];
int low[N],dfn[N],timer=0;
int scc_id[N],scc_cnt=0;
bool instack[N];
stack<int> st;
void dfs(int u) {
    dfn[u] = low[u] = ++timer;
    st.push(u);
    instack[u]=true;
    for (int v:adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[v],low[u]);
        }
        else if (instack[v]) {
            low[u] = min(dfn[v],low[u]);
        }
    }
    if (dfn[u]==low[u]) {
        scc_cnt++;
        while (true) {
            int v = st.top();
            st.pop();
            instack[v] = false;
            scc_id[v] = scc_cnt;
            if (v==u) break;
        }
    }
}
int main() {
    int m,n,q;
    cin>>n>>m>>q;
    while (m--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) dfs(i);
    }
    for (int u=1;u<=n;u++) {
        for (int v : adj[u]) {
            if (scc_id[u]!=scc_id[v]) {
                dag_adj[scc_id[u]].push_back(scc_id[v]);
            }
        }
    }
    for (int i=1;i<=scc_cnt;i++) {
        sort(dag_adj[i].begin(),dag_adj[i].end());
        dag_adj[i].erase(unique(dag_adj[i].begin(),dag_adj[i].end()),dag_adj[i].end());
    }
    for (int i=1;i<=scc_cnt;i++) dp[i][i] = 1;
    for (int i=1;i<=scc_cnt;i++) {
        for (int next_scc:dag_adj[i]) {
            dp[i]|=dp[next_scc];
        }
    }
    while (q--) {
        int u,v;
        cin>>u>>v;
        cout << (dp[scc_id[u]][scc_id[v]]?"YES":"NO") << "\n";
    }
}