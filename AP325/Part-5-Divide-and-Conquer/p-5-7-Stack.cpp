#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    cin>>n;
    vector<LL> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    v.push_back(0);
    stack<LL> st;
    LL max_size=0;
    for (int i=0;i<n+1;i++) {
        while (!st.empty()&&v[i]<v[st.top()]) {
            LL h = v[st.top()];
            st.pop();
            LL w = (st.empty()?i:i-st.top()-1);
            max_size = max(max_size,h*w);
        }
        st.push(i);
    }
    cout << max_size;
}