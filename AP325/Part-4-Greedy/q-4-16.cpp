#include <bits/stdc++.h>
using namespace std;
struct item{
    int t,f;
};
bool cmp(item i1,item i2) {
    return i1.t<i2.t    ;
}

int main() {
    int n;
    cin>>n;
    vector<item> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].t;
    }
    for (int i=0;i<n;i++) {
        cin>>v[i].f;
    }
    sort(v.begin(),v.end(),cmp);
    long long ans=0,t=0;
    for (auto i : v) {
        t+=i.t;
        ans+= i.f-t;
    }
    cout << ans;
}