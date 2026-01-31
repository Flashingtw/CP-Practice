#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
const int LOG = 20;

int n,q;
int val[N];
int st[N][LOG];

int main() {
    cin>>n>>q;
    for (int i=0;i<n;i++) {
        cin>>val[i];
        st[i][0] = val[i];
    }
    for (int j=1;j<LOG;j++) {
        for (int i=0;i+(1<<j)<=n;i++) {
            int half = 1<<(j-1);
            int left_part = st[i][j-1];
            int right_part = st[i+half][j-1];
            st[i][j] = min(left_part,right_part);
        }
    }
    while (q--) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        int len = b-a+1;
        int k = __lg(len);
        cout << min(st[a][k],st[b-(1<<k)+1][k]) << "\n";
    }
}