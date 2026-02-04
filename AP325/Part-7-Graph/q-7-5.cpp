#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,p;
    int lr[2];
    cin>>n>>p>>lr[0]>>lr[1];
    lr[0] = -lr[0];
    vector<int> point(n);
    for (int i=0;i<n;i++) {
        cin>>point[i];
    }

    vector<int> dis(n,-1);
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int np = q.front();
        q.pop();
        if (np==p) break;
        for (int i : lr) {
            int st = np+i;
            if (st>=n||st<0||dis[st]!=-1) continue;
            st = point[st];//jump
            if (st>=n||st<0||dis[st]!=-1) continue;
            dis[st] = dis[np]+1;
            q.push(st);
        }
    }
    cout << dis[p];
}