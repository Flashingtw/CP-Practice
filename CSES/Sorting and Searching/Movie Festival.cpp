#include <bits/stdc++.h>
using namespace std;
struct movie {
    int s,f;
};
int main() {
    int n;
    cin>>n;
    vector<movie> v(n);
    for (int i=0;i<n;i++) cin>>v[i].s>>v[i].f;
    sort(v.begin(),v.end(),[](auto &a,auto&b) {
        return a.f<b.f;
    });
    int current_time=0,ans=0;
    for (int i=0;i<n;i++) {
        if (v[i].s>=current_time) {
            ans++;
            current_time = v[i].f;
        }
    }
    cout << ans;
}