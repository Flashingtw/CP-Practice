#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 30005;
vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN], sz[MAXN];
int timer_dfs = 0;
int saved[MAXN];

void dfs(int u, int p) {
    dfn[u] = low[u] = ++timer_dfs;
    sz[u] = 1;
    
    for (int v : adj[u]) {
        if (v == p) continue; 
        
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            dfs(v, u);
            sz[u] += sz[v]; 
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                saved[u] += sz[v];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int K;
    cin >> K;
    
    dfs(K, -1);
    
    int max_saved = 0;
    int best_u = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (i == K || dfn[i] == 0) continue;
        
        if (saved[i] > max_saved) {
            max_saved = saved[i];
            best_u = i;
        }
    }
    
    if (max_saved == 0) {
        cout << 0 << "\n";
    } else {
        int infected = sz[K] - max_saved;
        cout << best_u << " " << infected << "\n";
    }
    
    return 0;
}