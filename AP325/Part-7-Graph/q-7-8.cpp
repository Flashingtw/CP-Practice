#include <bits/stdc++.h>
using namespace std;
int n,m;//n點m條邊
vector<int> adj[10005];//連結串列
int draw[10005];
bool bfs(int s) {
    queue<int> q;
    q.push(s);
    draw[s] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i : adj[now]) {
            if (draw[i]==-1){
                draw[i] = (draw[now]?0:1);
                q.push(i);
            }
            else {
                if (draw[i]==draw[now]) return false;
            }
        }
    }
    return true;
}
int main() {
    int T;
    cin>>T;
    for (int picture=0;picture<T;picture++) {
        cin>>n>>m;
        fill(draw,draw+n,-1);
        //無向圖
        for (int i=0;i<m;i++) {
            int from,to;
            cin>>from>>to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        //BFS
        bool yes = false;
        for (int i=0;i<n;i++) {
            if (draw[i]==-1) {
                if (!bfs(i)) {
                    yes = true;
                    break;
                }
            }
        }
        if (yes) cout << "no\n";
        else cout << "yes\n";
        for (int i=0;i<n;i++) adj[i].clear();
    }
}