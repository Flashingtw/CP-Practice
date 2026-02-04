#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int mid = v[n/2];
    long long ans=0;
    for (int i=0;i<n;i++) {
        ans+=abs(mid-v[i]);
    }
    cout << ans;
}