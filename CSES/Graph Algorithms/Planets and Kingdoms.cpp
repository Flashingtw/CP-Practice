#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

vector<int> adj[N];
int dfn[N],low[N],timer;
bool instack[N];
stack<int> st;
int scc_cnt;
int scc_id[N];

void dfs(int u) {
    dfn[u] = low[u] = ++timer;
    st.push(u);
    instack[u] = true;
    for (int v:adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u]=min(low[u],low[v]);//繼承
        }
        else if (instack[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u]==dfn[u]) {
        scc_cnt++;
        while (1) {
            int v = st.top();
            st.pop();
            instack[v] = false;
            scc_id[v] = scc_cnt;
            if (u==v) break;
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) dfs(i);
    }
    cout << scc_cnt << "\n";
    for (int i=1;i<=n;i++) {
        cout << scc_id[i] << ' ';
    }
}