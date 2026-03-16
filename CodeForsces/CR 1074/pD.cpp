#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m,h;
    cin>>n>>m>>h;
    vector<long long> v(n+1);
    vector<long long> cur(n+1);
    for (int i=1;i<=n;i++) {
        cin>>v[i];
        cur[i]=v[i];
    }
    vector<int> st;
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        cur[a]+=b;
        st.push_back(a);
        if (cur[a]>h) {
            for (int idx :st) cur[idx] = v[idx];
            st.clear();
        }
    }
    for (int i = 1; i <= n; i++) cout << cur[i] << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    while (n--) solve();
}