#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
//AI
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n, t, k, r;
    if (!(cin >> m >> n >> t >> k >> r)) return 0;

    vector<ll> c(t);
    for (int i = 0; i < t; i++) {
        cin >> c[i];
    }

    ll row_start = max(1LL, r - k + 1);
    ll row_end = min(m - k + 1, r);
    ll valid_rows = max(0LL, row_end - row_start + 1);
    ll invalid_rows = (m - k + 1) - valid_rows;


    int target_one_parity = ((k * k) % 2 == 0) ? 1 : 0;

    vector<ll> points;
    points.push_back(1);
    points.push_back(n - k + 2);

    for (ll val : c) {
        if (val + 1 <= n - k + 1) points.push_back(val + 1);

        if (val - k + 1 >= 1) points.push_back(val - k + 1);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    ll count_satisfying_intervals = 0;

    for (size_t i = 0; i < points.size() - 1; i++) {
        ll L = points[i];
        ll R = points[i+1];

        if (L > n - k + 1) break;


        ll window_end = L + k - 1;
        ll window_start_minus_1 = L - 1;

        ll ones_up_to_end = upper_bound(c.begin(), c.end(), window_end) - c.begin();
        ll ones_up_to_start_prev = upper_bound(c.begin(), c.end(), window_start_minus_1) - c.begin();

        ll ones_in_window = ones_up_to_end - ones_up_to_start_prev;

        if (ones_in_window % 2 == target_one_parity) {
            count_satisfying_intervals += (R - L);
        }
    }

    ll ans = 0;

    ans += count_satisfying_intervals * valid_rows;

    if (target_one_parity == 0) {
        ans += (n - k + 1) * invalid_rows;
    }

    cout << ans << endl;

    return 0;
}
