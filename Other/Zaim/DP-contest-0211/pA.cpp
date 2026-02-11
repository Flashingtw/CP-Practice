#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    vector<int> dp(1e6+5,0);
    for(int i:v) dp[i]++;
    for(int i=1;i<=1e6;i++){
        for(int num=i+i;num<=1e6;num+=i) dp[num]+=dp[i];
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout << dp[num] << " ";
    }
}