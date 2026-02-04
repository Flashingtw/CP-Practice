#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    multiset<int> t;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        t.insert(num);
    }
    for (int i=0;i<m;i++) {
        int num;
        cin>>num;
        auto it = t.upper_bound(num); //嚴格大於查找數字
        if (it==t.begin()) {
            cout << "-1\n";
        }
        else {
            --it;
            cout << *it << "\n";
            t.erase(it);
        }
    }
}