#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long ans=1e18;
int n;
void rec(int c,long long l,long long r) {
    if (c==n) {
        ans=min(ans,abs(l-r));
        return;
    }
    rec(c+1,l+v[c],r);
    rec(c+1,l,r+v[c]);
}
int main() {
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++) cin>>v[i];
    rec(0,0,0);
    cout << ans;
}