#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    //pos[i] mean i in where position
    //x[i] mean position i is what
    vector<int> x(n+1),pos(n+1);
    for (int i=1;i<=n;i++) {
        cin>>x[i];
        pos[x[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i + 1] < pos[i]) {
            ans++;
        }
    }
    while (k--) {
        int a,b;
        cin>>a>>b;
        set<int> check;
        int r = x[a],s = x[b];
        if (r>1) check.insert(r-1);
        if (r<n) check.insert(r);
        if (s>1) check.insert(s-1);
        if (s<n) check.insert(s);
        //原本如果數字比較大數字會++ 先減回來
        for (int val : check) {
            if (pos[val+1]<pos[val]) {
                ans--;
            }
        }
        swap(x[a],x[b]);
        pos[r] = b;
        pos[s] = a;
        //交換後的
        for (int val : check) {
            if (pos[val+1]<pos[val]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}