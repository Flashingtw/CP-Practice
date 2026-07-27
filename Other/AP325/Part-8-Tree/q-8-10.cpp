#include <bits/stdc++.h>
using namespace std;
#define N 100010
int p[N],deg[N]={0};
int ans=0;

int main() {
    int n;
    cin>>n;
    for (int i=1;i<n;i++) {
        cin>>p[i];
        deg[p[i]]++;
    }
    queue<int> q;
    for (int i=0;i<n;i++) {
        if (deg[i]==0) q.push(i);
    }
    int track[N];
    //0 empty 1 cover 2 build
    fill(track,track+n,0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (track[p[v]]==2) {
            track[v]=1;
        }
        if (track[v]==0&&track[p[v]]!=2) {
            track[p[v]] = 2;
            ans++;
        }
        if (--deg[p[v]]==0&&p[v]!=0) q.push(p[v]);
    }
    cout << ans;
}