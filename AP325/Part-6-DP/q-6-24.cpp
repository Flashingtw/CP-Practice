#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005; // 1e6 + 5
int n;
int h[MAXN];       // 高度
long long v[MAXN]; // 價值 use longlong
vector<int> lc,rc; // lc leftTree rc rightTree
pair<long long, long long> dfs(int u) {
    if (u == 0) return {0, 0};
    pair<long long, long long> L = dfs(lc[u]);
    pair<long long, long long> R = dfs(rc[u]);
    // 計算 g[u] (安全組合)
    // 如果子節點高度小於當前高度，取 f (無限制)，否則取 g (受限)
    long long l_safe = (h[lc[u]] < h[u]) ? L.first : L.second;
    long long r_safe = (h[rc[u]] < h[u]) ? R.first : R.second;
    long long g_val = l_safe + r_safe;
    //計算 f[u]最大價值
    long long f_val = max({v[u], g_val, L.first, R.first});

    return {f_val, g_val};
}

int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>v[i];
    lc.resize(n+1,0);
    rc.resize(n+1,0);
    vector<int> st;
    for (int i=1;i<=n;i++) {
        int lp=0;
        //MAXHEAP TREE
        while (!st.empty()&&h[st.back()]<h[i]) {
            lp = st.back();
            st.pop_back();
        }
        lc[i] = lp;//最後pop節點為左子樹
        if (!st.empty()) rc[st.back()] = i; //若沒有就是右子樹
        st.push_back(i);
    }
    //st[0]為ROOT
    cout << dfs(st[0]).first;
}