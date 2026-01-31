#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    multiset<int> ms;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        auto it = ms.upper_bound(num);
        if (it==ms.end()) {
            ms.insert(num);
            continue;
        }
        ms.erase(it);
        ms.insert(num);
    }
    cout << ms.size();
}