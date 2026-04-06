#include <bits/stdc++.h>
using namespace std;
struct item{
    int v,w,num;
};
int main(){
    int n,x;
    cin>>n>>x;
    vector<item> inf;
    vector<item> v;
    for(int i=0;i<n;i++) {
        int val,w,num;
        cin>>val>>w>>num;
        if(num==-1) inf.push_back({val,w,-1});
        else v.push_back({val,w,num});
    }
    vector<item> itm;
    for(auto [val,w,num]:v){
        for(int i=1;i<=num;i<<=1){
            itm.push_back({val*i,w*i,1});
            num-=i;
        }
        if(num>0){
            itm.push_back({val*num,w*num,1});
        }
    }
    vector<int> dp(x+1,0);
    for(auto [val,w,num]:itm){
        for(int i=x;i>=w;i--){
            dp[i]=max(dp[i],dp[i-w]+val);
        }
    }
    for(auto [val,w,num]:inf){
        for(int i=w;i<=x;i++){
            dp[i]=max(dp[i],dp[i-w]+val);
        }
    }
    cout << dp[x];
}