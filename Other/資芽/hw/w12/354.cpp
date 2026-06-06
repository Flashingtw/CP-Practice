#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;

    vector<pair<long long, long long>> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }

    vector<long long> dists;
    dists.reserve(n * (n - 1) / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dx = pts[i].first - pts[j].first;
            long long dy = pts[i].second - pts[j].second;
            long long d2 = dx * dx + dy * dy;
            dists.push_back(d2);
        }
    }

    sort(dists.begin(), dists.end());

    long long total_pairs = 0;
    long long count = 1;

    for (size_t i = 1; i < dists.size(); ++i) {
        if (dists[i] == dists[i - 1]) {
            count++;
        } else {
            total_pairs += count * (count - 1) / 2;
            count = 1;
        }
    }
    if (!dists.empty()) {
        total_pairs += count * (count - 1) / 2;
    }

    cout << total_pairs << "\n";
}