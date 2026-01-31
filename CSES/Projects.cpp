#include <bits/stdc++.h>
using namespace std;
struct project {
    int s,e,w;
    bool operator<(project b) {
        return e<b.e;
    }
};
int main() {
    int n;
    cin>>n;
    vector<project> v(n);
    for (int i=0;i<n;i++) cin>>v[i].s>>v[i].e>>v[i].w;
    sort(v.begin(),v.end());
    vector<int> ends;
    for (auto& p : v) {
        ends.push_back(p.e);
    }
    vector<long long> dp(n);//dp[i] mean the ith project doing max weight
    for (int i=0;i<n;i++) {
        long long op1 = (i==0)?0:dp[i-1];
        long long op2 = v[i].w;//
        auto it = lower_bound(ends.begin(),ends.end(),v[i].s);
        if (it!=ends.begin()) {
            it--;
            int idx = distance(ends.begin(),it);
            op2+=dp[idx];
        }
        dp[i] = max(op1,op2);
    }
    cout << dp[n-1];
}