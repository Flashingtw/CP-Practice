#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct item{
    int l,num;
};
int dp[50005];
int main(){
    for(int i=0;i<=50001;i++) dp[i] = INF;
    int n,w;
    cin>>n>>w;
    vector<pii> aaa(n);
    for(int i=0;i<n;i++){
        int l,c;
        cin>>l>>c;
        aaa[i]={l,c};
    }
    vector<item> v;
    for(auto [l,c]:aaa){
        int cnt=1;
        while(cnt<c){
            c-=cnt;
            v.push_back({l*cnt,cnt});
            cnt<<=1;
        }
        if(c>0){
            v.push_back({l*c,c});
        }
    }
    dp[0]=0;
    for(auto [l,num]:v){
        for(int i=w;i>=l;i--){
            dp[i] = min(dp[i],dp[i-l]+num);
        }
    }
    if(dp[w]!=INF){
        cout << dp[w];
    }
    else cout << -1;
}