#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e17;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, q;
    if (!(cin >> n >> m >> k >> q)) return 0;
    
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<long long> bt(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    for (int i = 0; i < k; ++i) {
        int u;
        long long t;
        cin >> u >> t;
        if (t < bt[u]) {
            bt[u] = t;
            pq.push({t, u});
        }
    }
    
    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (t > bt[u]) continue;
        for (int v : g[u]) {
            if (bt[u] + 1 < bt[v]) {
                bt[v] = bt[u] + 1;
                pq.push({bt[v], v});
            }
        }
    }
    
    while (q--) {
        int sa, sb;
        cin >> sa >> sb;
        
        priority_queue<pair<long long, int>> q_pq;
        vector<long long> max_t(n + 1, -1);
        
        max_t[sa] = bt[sa];
        q_pq.push({bt[sa], sa});
        
        while (!q_pq.empty()) {
            auto [t, u] = q_pq.top();
            q_pq.pop();
            if (t < max_t[u]) continue;
            for (int v : g[u]) {
                long long nt = min(t, bt[v]);
                if (nt > max_t[v]) {
                    max_t[v] = nt;
                    q_pq.push({nt, v});
                }
            }
        }
        
        long long ans = max_t[sb];
        if (ans == -1) {
            cout << -1 << '\n';
        } else if (ans == INF) {
            cout << -164253 << '\n';
        } else {
            cout << ans - 1 << '\n';
        }
    }
    
    return 0;
}