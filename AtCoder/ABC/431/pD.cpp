#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll dp[125005];
struct part{
    ll w,h,b;
};
int main(){
    int n;
    cin>>n;
    vector<part> v(n);
    ll t_w=0,base=0;
    fill(dp,dp+250005,-INF);
    for(int i=0;i<n;i++){
        cin>>v[i].w>>v[i].h>>v[i].b;
        t_w+=v[i].w;
        base+=v[i].b;
    }
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=125000;j>=v[i].w;j--){
            dp[j] = max(dp[j],dp[j-v[i].w]+(v[i].h-v[i].b));
        }
    }
}