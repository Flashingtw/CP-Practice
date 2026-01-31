#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int main(){
    int n;
    cin>>n;
    ll sum = 1LL*n*(n+1)/2;
    if(sum&1) {
        cout << "0";
        return 0;
    }
    int target = sum/2;
    vector<int> dp(target+1,0); //dp[i]為湊出i的方法數
    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=target;j>=i;j--){
            dp[j] = (dp[j]+dp[j-i])%mod;
        }
    }
    cout << dp[target];
}
