#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v;
    int len =0;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        auto it = lower_bound(v.begin(),v.end(),num);
        if (it==v.end()) v.push_back(num);
        else *it = num;//指標設為數字
    }
    cout << v.size();
}