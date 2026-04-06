#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
    IO
    int n, t;
    cin >> n >> t;
    vector<int> st;
    int ans = 0;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        while (!st.empty() and st.back() <= x) {
            ans += st.back();//分數
            x += st.back();//加總
            st.pop_back();//清除
        }
        if (x <= t) st.push_back(x);
    }
    for (auto x : st) ans += x;
    cout << ans;
}