#include <bits/stdc++.h>
using namespace std;
#define N 100010
int p[N],deg[N]={0};

int main() {
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        cin>>p[i];
        deg[p[i]]++;
    }
    int mark[N] = {0};
    queue<int> q;
    for (int i=0;i<n;i++) {
        if (deg[i]==0) q.push(i);
    }
    int total=0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v==0) break;
        if (mark[v]==0) {//if 0 -> chose
            total++;
            mark[p[v]]=1;//1mean got banned
        }
        if (--deg[p[v]]==0) q.push(p[v]);
    }
    if (mark[0]==0) total++;
    cout << total;
}