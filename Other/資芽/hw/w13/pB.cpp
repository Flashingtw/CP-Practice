#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN], timer;
bool is_cut[MAXN];

void dfs(int u, int p = -1) {
    dfn[u] = low[u] = ++timer;
    int children = 0;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] >= dfn[u] && p != -1) {
                is_cut[u] = true;
            }
            children++;
        }
    }
    
    if (p == -1 && children > 1) {
        is_cut[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (is_cut[i]) {
            cout << i << "\n";
        }
    }
    
    return 0;
}