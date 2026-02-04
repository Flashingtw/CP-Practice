#include <bits/stdc++.h>
using namespace std;
vector<int> memo;
vector<int> v;

int dp(int goal,int n) {
    if (memo[goal]>=0) return memo[goal];
    int imax=0;
    for (int i=0;i<n;i++) {
        if (goal & (1<<i)) {
            int k = dp(goal^(1<<i),n);
            imax = max(imax,k);
        }
    }
    memo[goal]=imax+v[goal];
    return memo[goal];
}
int main() {
    int n;
    cin>>n;
    int m = 1<<n;
    memo.resize(m,-1);
    v.resize(m);
    for (int i=0;i<m;i++) cin>>v[i];
    memo[0] = v[0];
    cout << dp(m-1,n);
}