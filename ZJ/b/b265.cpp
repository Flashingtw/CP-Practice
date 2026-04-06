#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        map<vector<int>, int> mp;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v(5);
            for (int j = 0; j < 5; j++) {
                cin >> v[j];
            }
            sort(v.begin(), v.end());
            mp[v]++;
            if (mp[v] > mx) {
                mx = mp[v];
            }
        }

        int ans = 0;
        for (auto const& [vec, cnt] : mp) {
            if (cnt == mx) {
                ans += cnt;
            }
        }
        cout << ans << '\n';
    }
}