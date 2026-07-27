#include <deque>
#include <iostream>
using namespace std;
int main() {
    deque<pair<int,int>> max_q,min_q;
    int n,k;
    cin>>n>>k;
    int max_diff=0;
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        if (max_q.front().second<=i-k) {
            max_q.pop_front();
        }
        while (!max_q.empty()&&max_q.back().first<=a) {
            max_q.pop_back();
        }
        max_q.emplace_back(a,i);

        if (min_q.front().second<=i-k) {
            min_q.pop_front();
        }
        while (!min_q.empty()&&min_q.back().first>=a) {
            min_q.pop_back();
        }
        min_q.emplace_back(a,i);

        int diff = max_q.front().first-min_q.front().first;
        max_diff = max(diff,max_diff);
    }
    cout << max_diff;
}