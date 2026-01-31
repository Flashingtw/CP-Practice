#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Job {
    int id;
    int s, d, t; // s: start, d: deadline, t: duration
};

int main() {
    // 優化 IO 速度
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    if (cin >> n) {
        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i].id = i;
            cin >> jobs[i].s >> jobs[i].d >> jobs[i].t;
        }

        // 建立索引陣列來進行排列 [0, 1, 2, ..., n-1]
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        int max_total_idle = -1;

        // 嘗試所有排列組合 (8! = 40320 次，非常快)
        do {
            // 步驟 1: 檢查此順序是否合法 (使用最早開始時間策略)
            int current_time = 0;
            bool valid = true;

            // 用來計算前 n-1 個任務的總時長
            int sum_duration_prev = 0;

            for (int i = 0; i < n; ++i) {
                int idx = p[i];
                // 任務最早能開始的時間：到達時間 s 或 上個任務結束時間
                int start = max(current_time, jobs[idx].s);

                // 如果做完會超過截止時間，則此排列無效
                if (start + jobs[idx].t > jobs[idx].d) {
                    valid = false;
                    break;
                }

                // 更新當前時間
                current_time = start + jobs[idx].t;

                // 累加除了最後一個任務以外的所有時長 (用於公式)
                if (i < n - 1) {
                    sum_duration_prev += jobs[idx].t;
                }
            }

            if (valid) {
                int first_job_idx = p[0];
                int last_job_idx = p[n - 1];
                int last_start_max = jobs[last_job_idx].d - jobs[last_job_idx].t;
                int first_start_min = jobs[first_job_idx].s;
                int current_idle = last_start_max - first_start_min - sum_duration_prev;
                if (current_idle > max_total_idle) {
                    max_total_idle = current_idle;
                }
            }
        } while (next_permutation(p.begin(), p.end()));
        cout << max_total_idle << endl;
    }
    return 0;
}