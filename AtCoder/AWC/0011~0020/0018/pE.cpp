#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 2e9;
int dp[505][55];
int main(){
    int n,k,b;
    cin>>n>>k>>b;
    vector<pii> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<505;i++){
        for(int j=0;j<55;j++) dp[i][j]=INF;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int K=k;K>=1;K--){
            for(int B=b;B>=v[i].first;B--){
                if(dp[B-v[i].first][K-1]<v[i].second){
                    dp[B][K]=min(dp[B][K],v[i].second);
                }
            }
        }
    }
    int ans=0;
    for(int j=k;j>=0;j--){
        for(int i=0;i<=b;i++){
            if(dp[i][j]!=INF) {ans=j; break;}
        }
        if(ans!=0) break;
    }
    cout << ans;
}