#include <bits/stdc++.h>
using namespace std;
#define N 10005
int p[N];

struct EDGE {
    int u,v,w;
};

bool cmp(EDGE &a,EDGE &b) {
    return a.w<b.w;
}

int rfind(int x) {
    if (p[x]==x) return x;
    return p[x] = rfind(p[x]);
}

int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) p[i] = i;
    vector<EDGE> edges;
    for (int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(),cmp);
    int cost=0,cnt=0;
    for (auto i : edges) {
        int x = rfind(i.u);
        int y = rfind(i.v);
        if (x==y) continue;
        p[x] = y;
        cost+=i.w;
        cnt++;
    }
    cout << (cnt==n-1?cost:-1);
}