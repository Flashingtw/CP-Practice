#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int LOG = 20;
int up[N][LOG];
int n,q;

void build() {
    for (int j=1;j<LOG;j++) {
        for (int i=1;i<=n;i++) {
            int half = up[i][j-1];
            if (half==0) up[i][j] = 0;//just a check
            else up[i][j] = up[half][j-1];
        }
    }
}
int query(int node,int k) {
    for (int j=0;j<LOG;j++){
        if ((k>>j)&1) {
            node = up[node][j];
        }
    }
    return node;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    for (int i=2;i<=n;i++) cin>>up[i][0];
    build();
    while (q--) {
        int a,k;
        cin>>a>>k;
        int ans = query(a,k);
        cout << (ans==0?-1:ans) << "\n";
    }
}