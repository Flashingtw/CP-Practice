#include <bits/stdc++.h>
using namespace std;
struct Line{
    int l,r,exp;
};

int main() {
    int n;
    cin>>n;
    vector<Line> v(n,{0,0,0});
    vector<int> endT;
    for (int i=0;i<n;i++) {
        cin>>v[i].l>>v[i].r>>v[i].exp;
    }
    sort(v.begin(),v.end(),
        [&](auto &a,auto &b) {
            return a.r<b.r;
        });
    for (auto &i : v) endT.push_back(i.r);
    vector<int> dp(n,0);
    for (int i=0;i<n;i++) {
        auto it = lower_bound(endT.begin(),endT.end(),v[i].l);
        int j = distance(endT.begin(),it)-1;
        dp[i] = v[i].exp+(j<0?0:dp[j]);
        if (i!=0&&dp[i]<dp[i-1]) dp[i] = dp[i-1];
    }
    cout << dp[n-1];
}