#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

int sign(__int128 val) {
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

__int128 ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return (__int128)(x2 - x1) * (y3 - y1) - (__int128)(y2 - y1) * (x3 - x1);
}

bool check_intersect() {
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    __int128 cp1 = ccw(x1, y1, x2, y2, x3, y3);
    __int128 cp2 = ccw(x1, y1, x2, y2, x4, y4);
    __int128 cp3 = ccw(x3, y3, x4, y4, x1, y1);
    __int128 cp4 = ccw(x3, y3, x4, y4, x2, y2);

    if (sign(cp1) * sign(cp2) <= 0 && sign(cp3) * sign(cp4) <= 0) {
        if (cp1 == 0 && cp2 == 0 && cp3 == 0 && cp4 == 0) {
            return max(min(x1, x2), min(x3, x4)) <= min(max(x1, x2), max(x3, x4)) &&
                   max(min(y1, y2), min(y3, y4)) <= min(max(y1, y2), max(y3, y4));
        }
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        if (check_intersect()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}