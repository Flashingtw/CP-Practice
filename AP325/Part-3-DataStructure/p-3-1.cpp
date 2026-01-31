#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> p(n+1,0),h(n+1,0),deg(n+1);
    queue<int> q;
    for (int i=1;i<=n;i++) {
        int c;
        cin>>c;
        deg[i] = c;
        if (c==0) q.push(i);
        for (int j=0;j<c;j++) {
            int a;
            cin>>a;
            p[a]=i;
        }
    }
    int root = 0,total = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int f = p[v];
        total+=h[v];
        if (f==0) {
            root = v;
            break;
        }
        h[f] = max(h[f],h[v]+1);
        if (--deg[f]==0) {
            q.push(f);
        }
    }
    cout << root << "\n" << total;
}