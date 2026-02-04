#include <bits/stdc++.h>
using namespace std;
struct member {
    int p,c,m;
};
bool cmp(member &a ,member &b) {
    if (a.c != b.c) return a.c > b.c;
    return a.m < b.m;
}

int main() {
    int n;
    cin>>n;
    vector<member> v(n);
    for (int i=0;i<n;i++) cin>>v[i].p;
    for (int i=0;i<n;i++) cin>>v[i].c;
    for (int i=0;i<n;i++) cin>>v[i].m;
    sort(v.begin(),v.end(),cmp);
    int ans=0;
    map<int,int> mp;
    mp.insert({-1,0});
    for (int i=0;i<n;i++) {
        auto it = mp.upper_bound(v[i].m);//found first <= current val.m
        --it;
        int w = it->second + v[i].p;// weight it->second mean map's value , first is key
        ans = max(ans,w);
        it = mp.insert(it,{v[i].m,w});
        if (it->second<w) it->second = w;
        ++it;//just move right let another value's w upper rightnow weight
        while (it!=mp.end() && it->second <=w) {
            it = mp.erase(it);
        }
    }
    cout << ans;
}