#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct sword {
    int t;
    int w;
};

bool cmp(sword s1,sword s2) {
    return s1.t*s2.w<s2.t*s1.w;
}

int main() {
    int n;
    cin>>n;
    vector<sword> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].t;
    }
    for (int i=0;i<n;i++) {
        cin>>v[i].w;
    }
    sort(v.begin(),v.end(),cmp);
    long long ans = 0;
    long long t =0;
    for (int i=0;i<n;i++) {
        t+=v[i].t;
        ans += t*v[i].w;
    }
    cout << ans;
}