#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<long long> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    long long current=0,ans=-INT_MAX;
    for (int i=0;i<n;i++) {
        current +=v[i];
        ans = max(current,ans);
        current = max((long long)0,current);
    }
    cout << ans;
}