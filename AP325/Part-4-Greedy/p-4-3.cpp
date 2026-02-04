#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<long long> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long ans=0,prefix = 0;
    for (int i=0;i<n;i++) {
        prefix+=v[i];
        ans+=prefix;
    }
    cout << ans;
}