#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e4+5;
vector<vector<int>> dp(55,vector<int>(N,-1e9));
struct item{
    int p,c,w;
};
int main(){
    int n,s,t;
    cin>>n>>s>>t;
    vector<item> v(n);
    for(int i=0;i<n;i++){
        int p,c,w;
        cin>>p>>c>>w;
        v[i] = {p,c,w};
    }
    dp[0][0] = 0;
    for(int k=0;k<n;k++){
        auto [p,c,w] = v[k];
        for(int i=n;i>=1;i--){
            for(int j=s;j>=w;j--){
                dp[i][j] = max(dp[i][j],dp[i-1][j-w]+(p-c));
            }
        }
    }
    int ans=INF;
    for(int i=1;i<55;i++){
        for(int j=0;j<=s;j++){
            if(dp[i][j]>=t){
                ans= min(ans,i);
            }
        }
    }
    cout << (ans==INF?-1:ans);
}