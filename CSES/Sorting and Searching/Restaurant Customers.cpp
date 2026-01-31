#include <bits/stdc++.h>
using namespace std;
struct event {
    int time,type;
};
int main() {
    int n;
    cin>>n;
    vector<event> v;
    for (int i=0;i<n;i++) {
        int s,f;
        cin>>s>>f;
        v.push_back({s,1});
        v.push_back({f,-1});
    }
    sort(v.begin(),v.end(),[&](event &a,event&b) {
        return a.time<b.time;
    });
    int n_ppl=0,ans=0;
    for (auto & i : v) {
        n_ppl += i.type;
        ans = max(ans,n_ppl);
    }
    cout << ans;
}