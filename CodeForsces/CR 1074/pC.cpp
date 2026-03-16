#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int max_len = 0;
    int current_len = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) current_len = 1;
        else {
            if (v[i] == v[i-1] + 1) current_len++;
            else {
                max_len = max(max_len, current_len);
                current_len = 1;
            }
        }
    }
    max_len = max(max_len, current_len);
    cout << max_len << "\n";
}
int main() {
    int k;
    cin>>k;
    while (k--) solve();
}