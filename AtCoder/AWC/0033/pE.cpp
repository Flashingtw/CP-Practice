#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> dp(n+1);
    deque<int> dq;
    dp[1] = a[1];
    dq.push_back(1);
    for(int i=2;i<=n;i++){
        while(!dq.empty()&&dq.front()+k<i){
            dq.pop_front();
        }
        if(!dq.empty()){
            dp[i] = dp[dq.front()]+a[i];
        }
        while(!dq.empty()&&dp[dq.back()]>dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << dp[n];
}