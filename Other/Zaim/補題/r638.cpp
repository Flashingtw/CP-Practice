#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
ll num[N][N];
ll val[N];

ll n,p,q;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>val[i];
    cin>>p>>q;
    for(int i=0;i<n;i++){
        num[i][1] = val[i];
    }
    for(int j=2;j<=n;j++){
        for(int i=0;i<n;i++){
            num[i][j] = (num[i][j-1]*p)/q;
        }
    }
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    for(int i=0;i<n;i++){
        dp[i][i]=num[i][n];
    }
    for(int k=2;k<=n;k++){
        for(int i=0;i+k-1<n;i++){
            int j = i+k-1;
            dp[i][j] = max(num[i][n-k+1]-dp[i+1][j],num[j][n-k+1]-dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];
}