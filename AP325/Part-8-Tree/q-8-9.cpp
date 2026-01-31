#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> adj[N];
int main() {
    int n;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int parents[N];
    bool visit[N]={false};
    vector<int> order;
    parents[1]=0;
    visit[1]=true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int e : adj[u]) {
            if (!visit[e]) {
                visit[e] = true;
                parents[e] = u;
                q.push(e);
            }
        }
    }
    int ans=0;
    //0 uncover 1 cover 2 build
    int state[N]={0};
    for (int i=n-1;i>0;i--) {
        int u = order[i]; //rightnow node
        int p = parents[u]; // his father node
        if (state[u]==0&&state[p]!=2) {//father didn't build and not be cover
            state[p]=2;
            ans++;
        }
        else if (state[u]==2&&state[p]==0) {
            state[p]=1;
        }
    }
    if (state[1]==0) ans++;
    cout << ans;
}