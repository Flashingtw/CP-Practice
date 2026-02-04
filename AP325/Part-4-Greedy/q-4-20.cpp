#include <bits/stdc++.h>
using namespace std;
struct ppl {
    int s,t;
};
int main() {
    int n,x,y;
    cin>>n;
    cin>>x>>y;
    vector<ppl> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].s>>v[i].t;
    }
    sort(v.begin(),v.end(),[&](auto &a,auto &b) {
        return a.s<b.s;
    });
    int cur_end = x;
    int ans=0;
    int idx=0;
    while (cur_end<y) {
        int next_max = -1;
        while (idx < n && v[idx].s <= cur_end) {
            next_max = max(next_max, v[idx].t);
            idx++;
        }
        if (next_max<=cur_end) {
            cout << "-1" << "\n";
            return 0;
        }
        ans++;
        cur_end = next_max;
    }
    cout << ans;
}