#include <iostream>
#include <vector>
#include <algorithm> // 用於 sort

using namespace std;

int main() {
    // 1. 加速輸入輸出，避免 TLE
    cin.tie(0)->sync_with_stdio(0);

    int m, n;
    // 讀入 m (頂點數) 和 n (邊數)
    // 如果題目輸入反過來，請根據題目調整
    if (!(cin >> m >> n)) return 0;

    // 使用 vector<pair> 替代 vector<set>
    // 這能解決 Runtime Error，因為我們不再依賴頂點編號作為陣列索引
    vector<pair<int, int>> edges;
    edges.reserve(n); // 預先配置記憶體，提升效能

    bool no_duplicate = true; // 預設沒有重複邊

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        // 檢查自環 (Self-loop): 自己連自己
        if (u == v) {
            no_duplicate = false;
            // 為了讀取完整的輸入串流，建議不要立刻 break，除非這是單筆測資
            // 但如果為了搶時間，確定是單筆測資可以 break
        }

        // 統一邊的方向：保證 first < second
        // 這樣 (1, 3) 和 (3, 1) 就會變成一樣的 {1, 3}
        if (u > v) swap(u, v);

        edges.push_back({u, v});
    }

    // 如果讀取時已經發現自環，直接輸出失敗
    if (!no_duplicate) {
        cout << "Yes"; // 依照您原本的邏輯：失敗(有重複/自環)輸出 Yes
        return 0;
    }

    // 2. 排序 (Sort)
    // 排序後，相同的邊會排在一起。例如：{1,2}, {1,2}, {1,5}...
    sort(edges.begin(), edges.end());

    // 3. 掃描一次檢查相鄰是否有重複
    for (size_t i = 0; i < edges.size() - 1; i++) {
        // 檢查當前這條邊是否跟下一條邊一樣
        if (edges[i] == edges[i+1]) {
            no_duplicate = false;
            break;
        }
    }

    // 4. 輸出結果
    // no_duplicate == true  -> 通過 (沒有重複) -> yes
    // no_duplicate == false -> 失敗 (有重複)   -> Yes
    cout << (no_duplicate ? "yes" : "Yes");

    return 0;
}