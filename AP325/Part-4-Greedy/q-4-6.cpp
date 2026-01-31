#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct item {
    long long w;
    long long f;
};

bool cmp(item i1,item i2) {
    return i1.w*i2.f<i2.w*i1.f;
}

int main() {
    long long n;
    cin>>n;
    vector<item> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].w;
    }
    for (int i=0;i<n;i++) {
        cin>>v[i].f;
    }
    sort(v.begin(),v.end(),cmp);
    long long ans=0,w=v[0].w;
    for (int i=1;i<n;i++) {
        ans+=w*v[i].f;
        w+=v[i].w;
    }
    cout << ans;
}