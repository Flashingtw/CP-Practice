#include <bits/stdc++.h>
using namespace std;
#define N 100010
int p[N],deg[N]={0},r[N];
int f0[N]={0},f1[N];
int main() {
    int n;
    cin>>n>>f1[1];
    for (int i=2;i<=n;i++) {
        cin>>p[i]>>f1[i];
        deg[p[i]]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++) if (deg[i]==0) q.push(i);
    //f0[i] mean i node don't be chose's best value
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v==1) break;
        int rw = p[v];
        f0[rw] += max(f0[v],f1[v]);
        f1[rw] += f0[v];
        if (--deg[rw]==0) q.push(rw);
    }
    cout << max(f0[1],f1[1]);
}