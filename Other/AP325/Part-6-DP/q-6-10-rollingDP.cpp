#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,M,f;
    cin>>n>>M>>f;
    vector<int> v(n+1);
    int total=0;
    for (int i=1;i<=n;i++) {
        cin>>v[i];
        total+=v[i];
    }
    int L = M-f;
    vector<int> dp(L+1,0),Ldp(L+1,0);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<v[i];j++) {
            if (j>L) break;
            dp[j] = Ldp[j];
        }
        for (int j=v[i];j<=L;j++) {
            dp[j] = max(Ldp[j-v[i]]+v[i],Ldp[j]);
        }
        swap(Ldp,dp);
    }
    cout << total - Ldp[L];
}