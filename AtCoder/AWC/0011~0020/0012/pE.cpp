#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> v(n),dp(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    deque<ll> dq;
    dp[0]=v[0];
    dq.push_back(0);
    for(int i=1;i<n;i++){
        while(!dq.empty()&&dq.front()+k<i){
            dq.pop_front();
        }
        dp[i] = v[i]+dp[dq.front()];
        while(!dq.empty()&&dp[dq.back()]<dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << dp[n-1];
}