#include <bits/stdc++.h>
using namespace std;
#define N 200010
int w[N]={0};
int l[N],r[N];
int n,m;

int findw(int v) {
    if (v>=n) return w[v];
    w[v] = findw(l[v]) + findw(r[v]);
    return w[v];
}
int main() {
    cin>>n>>m;
    for (int i=n;i<2*n;i++) cin>>w[i];
    vector<int> BOX(m);
    for (int i=0;i<m;i++) cin>>BOX[i];
    for (int i=1;i<n;i++) {
        int node,lc,rc;
        cin>>node>>lc>>rc;
        l[node] = lc;
        r[node] = rc;
    }
    w[1] = findw(1);
    for (int i=0;i<m;i++) {
        int v=1;
        while (v<n) {
            if (w[l[v]] <= w[r[v]]) v = l[v];
            else v = r[v];
            w[v]+=BOX[i];
        }
        cout << v << " ";
    }
}