#include <bits/stdc++.h>
using namespace std;
#define N 200010
vector<int> child[N];
int color[N],counter[N];
int n,ans;
map<int,int> d;

void dfs(int v) {
    int cc = d[color[v]];
    counter[cc]++;
    ans = max(ans,counter[cc]);
    for (int e : child[v]) dfs(e);
    counter[cc]--;
}

int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>color[i];
    for (int i=1;i<n;i++) {
        int p,v;
        cin>>p>>v;
        child[p].push_back(v);
    }
    for (int i=0;i<n;i++) d.insert({color[i],0});
    int cnt=0;
    for (auto &v : d) v.second = cnt++;
    dfs(0);
    cout << ans;
}