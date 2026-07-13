#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,h;
    cin>>n>>h;
    vector<int> v(n+1,0);
    vector<int> diff(n+2,0);
    for (int i=1;i<=n;i++) {
        cin>>v[i];
        diff[i]=v[i]-v[i-1];
    }
    while (h--) {
        int a,b,val;
        cin>>a>>b>>val;
        diff[a]+=val;
        diff[b+1]-=val;
    }
    for (int i=1;i<=n;i++) {
        v[i] = diff[i]+v[i-1];
    }
    cout << *min_element(v.begin()+1,v.end());
}