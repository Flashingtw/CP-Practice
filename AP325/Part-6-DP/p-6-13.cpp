#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1,0);
    for (int i=1;i<=n;i++) {
        cin>>v[i];
    }

    vector<int> dp(n+1,1e9);
    deque<int> dq;
    for (int i=1;i<=n;i++) {
        while (!dq.empty()&&dq.front()<i-2*k-1) {
            dq.pop_front();
        }
        if (i<=k+1) {
            dp[i] = v[i];
        }
        else {
            dp[i] = dp[dq.front()] + v[i];
        }
        while (!dq.empty()&&dp[dq.back()]>=dp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int ans = 1e9;
    for (int i=n;i>=n-k;i--) {
        ans = min(ans,dp[i]);
    }
    cout << ans;
}