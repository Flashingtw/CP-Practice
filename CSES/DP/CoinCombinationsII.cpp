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
    vector<int> dp(x+1,0);
    dp[0]=1;
    for (auto a : c) {
        for (int i = a;i<=x;i++) {
            dp[i]+=dp[i-a];
            dp[i]%=MOD;
        }
    }
    cout << dp[x];
}