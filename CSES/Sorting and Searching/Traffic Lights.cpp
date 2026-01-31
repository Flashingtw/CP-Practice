#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int x,n;
    cin>>x>>n;
    set<int> s={0,x};
    multiset<int> ms = {x};
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        auto it = s.upper_bound(num);//right pos
        auto it_left = it;//left pos
        it_left--;
        auto it_find = ms.find(*it-*it_left);
        ms.erase(it_find);
        ms.insert(*it-num);
        ms.insert(num-*it_left);
        s.insert(num);
        cout << *ms.rbegin() << " ";
    }
}