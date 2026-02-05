#include <bits/stdc++.h>
using namespace std;
struct qs {
    int c,t;
};
int main() {
    int n,x;
    cin>>n>>x;
    int ans=0,time=0;
    map<int,int> mp;
    vector<qs> v(n);
    for (int i=0;i<n;i++) cin>>v[i].c>>v[i].t;
    for (int i=0;i<n;i++) {
        int t = v[i].t,c = v[i].c;
        if (time+max(1,t-mp[c])<=x) {
            time+=max(1,t-mp[c]);
            mp[c]++;
            ans++;
        }
        else {
            break;
        }
    }
    cout << ans;
}