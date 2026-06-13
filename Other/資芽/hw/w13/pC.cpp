#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
const int MAXM = 1000005;

struct Edge {
    int to;
    int id;
};

struct EdgeInfo {
    int u, v;
} input_edges[MAXM];

vector<Edge> adj[MAXN];
int dfn[MAXN], low[MAXN], timer;
bool is_bridge[MAXM]; 

void dfs(int u, int from_edge_id = -1) {
    dfn[u] = low[u] = ++timer;
    
    for (const auto& edge : adj[u]) {
        int v = edge.to;
        int id = edge.id;
        
        if (id == from_edge_id) continue; 
        
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > dfn[u]) {
                is_bridge[id] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        input_edges[i] = {u, v}; 
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    
    for (int i = 0; i < m; ++i) {
        if (is_bridge[i]) {
            cout << input_edges[i].u << " " << input_edges[i].v << "\n";
        }
    }
    
    return 0;
}