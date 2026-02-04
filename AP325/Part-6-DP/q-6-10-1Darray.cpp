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
    vector<int> dp(L+1,0);
    for (int i=1;i<=n;i++) {
        for (int j=L;j>=v[i];j--) {
            dp[j] = max(dp[j-v[i]]+v[i],dp[j]);
        }
    }
    cout << total - dp[L];
}