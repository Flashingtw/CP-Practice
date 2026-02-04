#include <bits/stdc++.h>
#define N 50100
using namespace std;
vector<int> c[N];
int v[N];
int n,m;
bool vis[N] = {false};

int dfs(int s) {
    int w = v[s];
    vis[s] = true;
    for (auto i : c[s]) {
        if (!vis[i]) {
            w+=dfs(i);
        }
    }
    return w;
}

int main() {
    cin>>n>>m;
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    for (int i=0;i<m;i++) {
        int n1,n2;
        cin>>n1>>n2;
        c[n1].push_back(n2);
        c[n2].push_back(n1);
    }
    int maxw=0;
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            maxw = max(maxw,dfs(i));
        }
    }
    cout << maxw;
}