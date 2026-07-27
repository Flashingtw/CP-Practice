#include <bits/stdc++.h>
using namespace std;

// 全域變數
int k, n; // k 對應題目中的 m (顏色總數/區段長度)
vector<int> arr; // 存放離散化後的顏色
int cnt[200005]; // 計數陣列 (假設顏色已離散化為 0~k)
int repeat_num = 0; // 目前視窗中有多少種顏色是「重複出現」的

// 增加顏色
void add(int c) {
    if (cnt[c] == 1) repeat_num++; // 原本有1個，變2個 -> 重複種類+1
    cnt[c]++;
}

// 移除顏色
void sub(int c) {
    cnt[c]--;
    if (cnt[c] == 1) repeat_num--; // 原本有2個，變1個 -> 重複種類-1
}

int solve(int le, int ri) {
    // 1. 遞迴終止條件
    if (ri - le + 1 < k) return 0;

    int m = (le + ri) / 2;

    // 2. 遞迴計算左右 (修正區間：[le, m] 與 [m+1, ri])
    int w = solve(le, m) + solve(m + 1, ri);

    // 3. 合併階段：處理「跨越中點」的區間
    // 定義：區間必須同時包含 m 和 m+1
    // start_min: 最左邊可能的起點 (確保終點至少碰到 m+1)
    // start_max: 最右邊可能的起點 (確保起點還在 m 左邊)
    int start_min = max(le, m - k + 2);
    int start_max = min(m, ri - k + 1);

    if (start_min > start_max) return w;

    // --- 開始滑動視窗 ---

    // A. 建立第一個視窗 [start_min, start_min + k - 1]
    int current_L = start_min;
    int current_R = start_min + k - 1;

    for(int i = current_L; i <= current_R; i++) {
        add(arr[i]);
    }

    if (repeat_num == 0) w++; // 如果沒有任何顏色重複，這是一個完美彩帶

    // B. 向右滑動，直到起點超過 start_max
    while (current_L < start_max) {
        sub(arr[current_L]); // 移除最左邊
        current_L++;

        current_R++;         // 加入最右邊
        add(arr[current_R]);

        if (repeat_num == 0) w++;
    }

    // C. 重置狀態 (Backtracking)
    // 這是分治法的關鍵：為了不影響上一層遞迴，必須把 cnt 陣列還原
    for(int i = current_L; i <= current_R; i++) {
        sub(arr[i]);
    }

    return w;
}

int main() {
    // 這裡需要加入讀取輸入、座標離散化的程式碼
    // 詳見前一次回答的完整範例
}