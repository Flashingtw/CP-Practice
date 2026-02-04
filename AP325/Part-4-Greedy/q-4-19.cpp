#include <bits/stdc++.h>
using namespace std;
struct event {
    int m;
    int t;
    int type;
};

int main() {
    int n;
    cin>>n;
    vector<event> v;
    for (int i=0;i<n;i++) {
        int m;
        cin>>m;
        int t;
        cin>>t;
        event e1(m,t,1);
        cin>>t;
        event e2(m,t,-1);
        v.push_back(e1);
        v.push_back(e2);
    }
    sort(v.begin(),v.end(),[&](auto &a,auto &b) {
        if (a.t!=b.t) return a.t<b.t;
        return a.type>b.type;
    });
    long long ans=0,current_num=0;
    for (int i=0;i<v.size();i++) {
        current_num+=v[i].m*v[i].type;
        ans = max(ans,current_num);
    }
    cout << ans;
}