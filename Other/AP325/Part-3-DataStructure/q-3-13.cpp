#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,l;
    cin>>n>>l;
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].first;
    }
    for (int i=0;i<n;i++) {
        cin>>v[i].second;
    }
    sort(v.begin(),v.end());

    deque<pair<int,int>> max_dq,min_dq;
    int m =0;
    for (auto i : v) {
        while (!max_dq.empty()&&i.first-max_dq.front().first>l) {
            max_dq.pop_front();
        }
        while (!max_dq.empty()&&max_dq.back().second<=i.second) {
            max_dq.pop_back();
        }
        max_dq.push_back(i);

        while (!min_dq.empty()&&i.first-min_dq.front().first>l) {
            min_dq.pop_front();
        }
        while (!min_dq.empty()&&min_dq.back().second>=i.second) {
            min_dq.pop_back();
        }
        min_dq.push_back(i);
        m = max(m,abs(max_dq.front().second-min_dq.front().second));
    }
    cout << m;
}