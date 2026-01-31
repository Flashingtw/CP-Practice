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
    sort(v.begin(),v.end());
    stack<int> st;
    for (auto i : v) {
        while (!st.empty()&&st.top()<=i.second) {
            st.pop();
        }
        st.push(i.second);
    }
    cout << st.size();
}