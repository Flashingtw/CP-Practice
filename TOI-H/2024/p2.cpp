#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
//AI
int main() {
    // 優化 IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n, t, k, r;
    if (!(cin >> m >> n >> t >> k >> r)) return 0;

    vector<ll> c(t);
    for (int i = 0; i < t; i++) {
        cin >> c[i];
    }

    // 1. 計算垂直方向的有效列數 (碰到第 r 列的子矩陣起始列數)
    // 起始列 i 必須滿足: i <= r 且 i + k - 1 >= r
    // => r - k + 1 <= i <= r
    // 同時必須在邊界內: 1 <= i <= m - k + 1
    ll row_start = max(1LL, r - k + 1);
    ll row_end = min(m - k + 1, r);
    ll valid_rows = max(0LL, row_end - row_start + 1);
    ll invalid_rows = (m - k + 1) - valid_rows;

    // 2. 判斷我們需要找奇數個 1 還是偶數個 1
    // k*k 總格數
    // 若 k*k 是偶數: 偶 = 奇(0) + 奇(1) -> 目標找 1 的數量為奇數
    // 若 k*k 是奇數: 奇 = 奇(0) + 偶(1) -> 目標找 1 的數量為偶數
    // 簡單記法: 目標 parity = (k * k % 2 == 0) ? 1 : 0;
    // 但題目要找的是「奇數個 0」。
    // 總數 Even: Odd 0s <-> Odd 1s.
    // 總數 Odd:  Odd 0s <-> Even 1s.
    int target_one_parity = ((k * k) % 2 == 0) ? 1 : 0;

    // 3. 收集水平掃描的關鍵點
    vector<ll> points;
    points.push_back(1);
    points.push_back(n - k + 2); // 結束點的下一個位置

    for (ll val : c) {
        // 當視窗左端 x 來到 val + 1 時，原本在 val 的 1 會離開視窗左邊
        if (val + 1 <= n - k + 1) points.push_back(val + 1);

        // 當視窗左端 x 來到 val - k + 1 時，原本在 val 的 1 會進入視窗右邊
        if (val - k + 1 >= 1) points.push_back(val - k + 1);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    ll count_satisfying_intervals = 0;

    // 4. 遍歷所有區段
    for (size_t i = 0; i < points.size() - 1; i++) {
        ll L = points[i];
        ll R = points[i+1];

        if (L > n - k + 1) break; // 超出合法視窗範圍

        // 計算視窗 [L, L + k - 1] 內有幾個 1
        // 利用 upper_bound 找前綴和
        // count = (index of last 1 <= end) - (index of first 1 >= start) + 1
        // 或者直接用前綴和概念: prefix(end) - prefix(start - 1)

        ll window_end = L + k - 1;
        ll window_start_minus_1 = L - 1;

        // upper_bound 回傳第一個 > key 的位置，減去 begin 就是小於等於 key 的個數
        ll ones_up_to_end = upper_bound(c.begin(), c.end(), window_end) - c.begin();
        ll ones_up_to_start_prev = upper_bound(c.begin(), c.end(), window_start_minus_1) - c.begin();

        ll ones_in_window = ones_up_to_end - ones_up_to_start_prev;

        if (ones_in_window % 2 == target_one_parity) {
            count_satisfying_intervals += (R - L);
        }
    }

    // 5. 計算最終答案
    ll ans = 0;

    // Case A: 子矩陣有蓋到第 r 列 (裡面的 1 數量由水平掃描決定)
    ans += count_satisfying_intervals * valid_rows;

    // Case B: 子矩陣完全沒蓋到第 r 列 (裡面的 1 數量永遠是 0，即偶數)
    // 只有當目標是找「偶數個 1」時，這些子矩陣才算數
    if (target_one_parity == 0) {
        // 水平方向合法的總共有 (n - k + 1) 種位置，垂直方向有 invalid_rows 種
        ans += (n - k + 1) * invalid_rows;
    }

    cout << ans << endl;

    return 0;
}
