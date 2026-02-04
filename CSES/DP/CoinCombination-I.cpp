#include <iostream>
#include <vector>
using namespace std;
const int MOD = int(1e9+7);

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> c;
    for (int i=0;i<n;i++) {
        int a;
        cin >> a;
        c.push_back(a);
    }
    int dp[x+1];
    dp[0]=1;
    for (int i=1;i<=x;i++) {
        dp[i]=0;
        for (auto a:c) {
            if (i-a<0) continue;
            dp[i]=(dp[i]+dp[i-a])%MOD;
        }
    }
    cout << dp[x];
}