#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n,x;
    cin>>n>>x;
    vector<pii> v;
    for(int cnt=0;cnt<n;cnt++){
        int w,val,c;
        cin>>w>>val>>c;
        for(int i=1;i<=c;i<<=1){
            v.push_back({w*i,val*i});
            c-=i;
        }
        if(c>0) v.push_back({w*c,val*c});
    }
    vector<int> dp(x+1,0);
    dp[0]=0;
    for(pii &it:v){
        int val = it.second;
        int w = it.first;
        for(int i=x;i>=w;i--){
            dp[i]=max(dp[i],dp[i-w]+val);
        }
    }
    cout << dp[x];
}
