#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].first;
    }
    for (int i=0;i<n;i++) {
        cin>>v[i].second;
    }
    sort(v.begin(),v.end(),greater());
    int total=0,max_y=-1;
    for (auto i : v) {
        if (i.second>max_y) {
            total++;
            max_y=i.second;
        }
    }
    cout << total;
}