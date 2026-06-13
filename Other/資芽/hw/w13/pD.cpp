#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

struct Edge {
    int to;
    long long w;
};

struct OrigEdge {
    int u, v;
    long long w;
};

int N, M;
long long S[MAXN];
vector<Edge> adj[MAXN];

int dfn[MAXN], low[MAXN], timer;
int scc_id[MAXN], scc_cnt;
bool in_stack[MAXN];
stack<int> st;

long long scc_weight[MAXN];
vector<Edge> dag[MAXN];
long long dp[MAXN];
bool visited_dag[MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    st.push(u);
    in_stack[u] = true;

    for (auto& edge : adj[u]) {
        int v = edge.to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        scc_cnt++;
        while (true) {
            int v = st.top();
            st.pop();
            in_stack[v] = false;
            scc_id[v] = scc_cnt;
            scc_weight[scc_cnt] += S[v];
            if (u == v) break;
        }
    }
}
long long solve_dag(int u) {
    if (visited_dag[u]) return dp[u];
    visited_dag[u] = true;

    long long max_next = 0;
    for (auto& edge : dag[u]) {
        max_next = max(max_next, edge.w + solve_dag(edge.to));
    }
    return dp[u] = scc_weight[u] + max_next;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    for (int i = 1; i <= N; ++i) {
        cin >> S[i];
    }

    vector<OrigEdge> orig_edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> orig_edges[i].u >> orig_edges[i].v >> orig_edges[i].w;
        adj[orig_edges[i].u].push_back({orig_edges[i].v, orig_edges[i].w});
    }

    for (int i = 1; i <= N; ++i) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 0; i < M; ++i) {
        int u = orig_edges[i].u;
        int v = orig_edges[i].v;
        long long w = orig_edges[i].w;

        if (scc_id[u] == scc_id[v]) {
            scc_weight[scc_id[u]] += w;
        } else {
            dag[scc_id[u]].push_back({scc_id[v], w});
        }
    }

    long long ans = 0;
    for (int i = 1; i <= scc_cnt; ++i) {
        ans = max(ans, solve_dag(i));
    }

    cout << ans << "\n";

    return 0;
}