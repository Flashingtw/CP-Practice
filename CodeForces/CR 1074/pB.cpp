#include <bits/stdc++.h>
using namespace std;
long long value(const vector<int>& a) {
    long long sum = 0;
    int pre_max = 0;
    for (int x : a) {
        pre_max = max(pre_max, x);
        sum += pre_max;
    }
    return sum;
}
void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    long long ans=value(v);
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            swap(v[i],v[j]);
            ans = max(ans,value(v));
            swap(v[i],v[j]);
        }
    }
    cout << ans << "\n";
}
int main() {
    int n;
    cin>>n;
    while (n--) solve();
}