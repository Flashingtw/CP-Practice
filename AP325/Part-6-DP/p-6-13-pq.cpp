#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1,0);
    for (int i=1;i<=n;i++) cin>>v[i];

    priority_queue<pair<int,int>> pq;
    vector<int> dp(n+1,1e9);
    dp[1] = v[1];
    pq.emplace(-v[1],1);//初始化
    for (int i=2;i<=n;i++) {
        if (i<=k+1) {
            dp[i] = v[i];
        }
        else {
            while (pq.top().second<i-2*k-1) pq.pop();
            dp[i] = -pq.top().first+v[i];
        }
        pq.emplace(-dp[i],i);
    }
    cout << (*min_element(dp.begin()+n-k,dp.end()));
}