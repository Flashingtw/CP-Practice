#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dp[3005][3005];
int main(){
    string s,t;
    cin>>s>>t;
    s = ' '+s;
    t = ' '+t;
    int n = s.size();
    int m = t.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = n,j = m;
    string ans;
    while(i>0&&j>0){
        if(s[i]==t[j]){
            ans+=s[i];
            i--;
            j--;
        }
        else if (dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else i--;
    }
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    cout << ans;
}