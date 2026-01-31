#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long max_sum=0;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        max_sum+=v[i];
    }
    vector<bool> dp(max_sum+1,false);
    dp[0] = true;
    for (int coin : v) {
        for (int i=max_sum;i>=coin;i--) {
            if (dp[i-coin]) {
                dp[i] = true;
            }
        }
    }
    vector<int> ans;
    for (int i=1;i<=max_sum;i++) {
        if (dp[i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}