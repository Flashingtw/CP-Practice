#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[10005];
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=k;j>=v[i];j--){
            dp[j] = max(dp[j-v[i]]+v[i],dp[j]);
        }
    }
    cout << dp[k];
}