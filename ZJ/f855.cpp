#include <bits/stdc++.h>
using namespace std;
struct L {
    int l,r;
};
int main() {
    int n;
    cin>>n;
    vector<L> v(n);
    for (int i=0;i<n;i++) cin>>v[i].l>>v[i].r;
    sort(v.begin(),v.end()
        ,[&](auto &a, auto &b){return a.l<b.l;});
    int ans=0,pos_l=0,pos_r=0;
    for (int i=0;i<n;i++) {
        if (v[i].l>pos_r) {
            ans+=pos_r-pos_l;
            pos_l = v[i].l;
        }
        pos_r = max(pos_r,v[i].r);
    }
    ans += pos_r-pos_l;
    cout << ans;
}