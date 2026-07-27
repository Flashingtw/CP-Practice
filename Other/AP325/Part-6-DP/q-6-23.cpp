#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,j;
    cin>>n;
    multiset<int> ms;// 走i步能獲得的最大數量為ms.size=i
    for (int i=0;i<n;i++) {
        int l,r;
        cin>>l>>r;
        auto it = ms.upper_bound(r);
        if (it!=ms.end()) {
            ms.erase(it);
        }
        ms.insert(l);
    }
    cout << ms.size();
}