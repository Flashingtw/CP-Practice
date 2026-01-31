#include <iostream>
using namespace std;

int main() {
    // 開啟加速，處理大量 IO 必備
    cin.tie(0)->sync_with_stdio(0);

    int n;
    if (!(cin >> n)) return 0;

    char c;
    // 模擬二維矩陣的讀取
    for (int i = 0; i < n; i++) {       // 行 (Row)
        for (int j = 0; j < n; j++) {   // 列 (Column)
            // 每次只讀一個字元
            // cin >> c 會自動跳過空白與換行，非常安全
            cin >> c;

            // 只有當 行數 == 列數 時 (主對角線)，才印出來
            if (i == j) {
                cout << c;
            }
            // 如果不是對角線，這個變數 c 在下一圈迴圈就會被覆蓋掉 (等同丟棄)
        }
    }

    return 0;
}