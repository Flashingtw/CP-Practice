#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
vector<int> dp(N,0);
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<N;i++) {
        for (int j=0;j<N;j+=i) {
            dp[j]++;
        }
    }
    while (n--) {
        int i;
        cin>>i;
        cout<<dp[i] << "\n";
    }
}