#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    string gdCode;
    cin >> gdCode;
    sort(b.begin(), b.end());
    vector<pair<int, int>> deathL, deathR;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it != b.end()) {
            deathR.push_back({*it - a[i], i});
        }
        if (it != b.begin()) {
            deathL.push_back({a[i] - *prev(it), i});
        }
    }
    sort(deathL.begin(), deathL.end());
    sort(deathR.begin(), deathR.end());
    int cur_pos = 0;
    int min_pos = 0;
    int max_pos = 0;
    int ptr_L = 0;
    int ptr_R = 0;
    int alive_cnt = n;
    vector<bool> is_dead(n, false);
    for (char move : gdCode) {
        if (move == 'L') cur_pos--;
        else cur_pos++;
        if (cur_pos < min_pos) {
            min_pos = cur_pos;
            int dist_moved_left = abs(min_pos);
            while (ptr_L < deathL.size() && deathL[ptr_L].first <= dist_moved_left) {
                int robot_idx = deathL[ptr_L].second;
                if (!is_dead[robot_idx]) {
                    is_dead[robot_idx] = true;
                    alive_cnt--;
                }
                ptr_L++;
            }
        }
        if (cur_pos > max_pos) {
            max_pos = cur_pos;
            int dist_moved_right = max_pos;
            while (ptr_R < deathR.size() && deathR[ptr_R].first <= dist_moved_right) {
                int robot_idx = deathR[ptr_R].second;
                if (!is_dead[robot_idx]) {
                    is_dead[robot_idx] = true;
                    alive_cnt--;
                }
                ptr_R++;
            }
        }
        cout << alive_cnt << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}