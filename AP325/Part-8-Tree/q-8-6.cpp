#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
int p[N],leng[N];
vector<int> adj[N];
int num[N];

int fnum(int x) {
    int h=1;
    for (int e : adj[x]) {
        h+=fnum(e);
    }
    return num[x]=h;
}

int main() {
    cin>>n;
    for (int i=2;i<=n;i++) {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    for (int i=2;i<=n;i++) cin>>leng[i];
    fnum(1);
    long long total=0;
    for (int i=1;i<=n;i++) {
        long long cnt = (long long)num[i]*(n-num[i]);
        total+= 2*cnt*leng[i];
    }
    cout << total;
}