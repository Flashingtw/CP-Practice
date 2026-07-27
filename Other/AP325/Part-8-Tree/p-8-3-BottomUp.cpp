#include <bits/stdc++.h>
using namespace std;
#define N 100010
int main() {
    int n;
    cin>>n;
    int deg[N],leng[N],parents[N],num[N];
    for (int i=1;i<n;i++) {
        cin>>parents[i]>>leng[i];
        deg[parents[i]]++;
    }
    parents[0]=-1;
    int medium=-1,total=0;
    queue<int> q;
    for (int i=0;i<n;i++) if (deg[i]==0) q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        num[v]++;//add its self
        if (medium<0&&num[v]>=n/2) {
            medium = v;
        }
        //上面來的還是下面來的人少 * 長度
        total += min(num[v], n-num[v]) * leng[v];
        num[parents[v]] += num[v];
        if (--deg[parents[v]]==0) q.push(parents[v]);
    }
    cout << medium << "\n" << total;
}