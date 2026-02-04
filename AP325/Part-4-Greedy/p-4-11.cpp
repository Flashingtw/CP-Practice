#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    cin>>n;
    vector<pair<LL,LL>> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    LL ans=0;
    pair<LL,LL> last = v[0];
    for (auto seg : v) {
        if (seg.first > last.second) {
            ans+=last.second-last.first;
            last = seg;
            continue;
        }
        last.second = max(last.second,seg.second);
    }
    ans+=last.second-last.first;
    cout << ans;
}