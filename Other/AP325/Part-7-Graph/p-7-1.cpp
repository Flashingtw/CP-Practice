#include <bits/stdc++.h>
#define N 102
using namespace std;

int n,m,s;//n point ,m side
vector<int> ll[N];
int d[N];

void bfs(int s) {
    bool visit[N] = {false};
    queue<int> q;
    q.push(s);
    visit[s] = true,d[s]=0;
    int cnt=0,total=0;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto i : ll[k]) {
            if (!visit[i]) {
                d[i] = d[k]+1;
                visit[i] = true;
                q.push(i);
                cnt++;
                total+=d[i];
            }
        }
    }
    cout << cnt << "\n" << total;
}

int main() {
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<m;i++) {
        int from,to;
        cin>>from>>to;
        ll[from].push_back(to);
    }
    bfs(s);
}