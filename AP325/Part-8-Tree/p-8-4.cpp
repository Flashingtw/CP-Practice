#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> child[N];
int height[N];

int dfs(int x) {
    if (height[x]>=0) return height[x];
    height[x] =0;
    for (int e : child[x]) {
        height[x] = max(height[x],dfs(e)+1);
    }
    return height[x];
}

int main() {
    int n,root;
    int parent[N]={0};
    cin>>n;
    for (int i=1;i<=n;i++) {
        int k,s;
        cin>>k;
        for (int j=0;j<k;j++) {
            cin>>s;
            parent[s]=i;
            child[i].push_back(s);
        }
    }
    for (root=1;root<=n;root++) {
        if (parent[root]==0) break;
    }
    int total_h = 0;
    for (int i=1; i<=n; i++)
        height[i]=-1;
    for (int i=1; i<=n; i++)
        total_h += dfs(i);
    cout << root << "\n" << total_h;
}