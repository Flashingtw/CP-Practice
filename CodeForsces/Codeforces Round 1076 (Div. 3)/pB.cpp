#include <iostream>
#include <vector>
#include <algorithm> // ¥Î©ó std::reverse

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        int target = n - i;

        if (p[i] != target) {
            int r = pos[target];
            reverse(p.begin() + i, p.begin() + r + 1);
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
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
}
