#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    vector<int> v;
    while (cin>>n) {
        v.push_back(n);
    }
    vector dp(v.size(),1);
    for (int i=0;i<v.size();i++) {
        for (int j=i;j>=0;j--) {
            if (v[j]>v[i]) {
                dp[i] = max(dp[j],dp[j]+1);
            }
        }
    }
}