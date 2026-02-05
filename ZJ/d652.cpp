#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> val;
int main(){
    cin>>n;
    val.resize(n);
    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;i++) dp[i][i]=val[i];
    for(int len=3;len<=n;len++){
        
    }
}