#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

struct Point {
    LL x, y;
};

vector<Point> p;
vector<Point> tmp;

// 計算 L1 距離
LL dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

LL solve(int le, int ri) {
    if (le + 1 >= ri) return 4e18;

    int mid = le + (ri - le) / 2;
    LL midX = p[mid].x;

    LL d = min(solve(le, mid), solve(mid, ri));
    vector<Point> v;
    int i = le, j = mid, k = le;
    tmp.clear();
    while (i < mid || j < ri) {
        Point current;
        if (i < mid && (j == ri || p[i].y < p[j].y)) current = p[i++];
        else current = p[j++];
        tmp.push_back(current);
        if (abs(current.x - midX) < d) {
            for (int idx = v.size() - 1; idx >= 0; idx--) {
                if (current.y - v[idx].y >= d) break;
                d = min(d, dist(current, v[idx]));
            }
            v.push_back(current);
        }
    }
    //回寫
    for (int idx = le; idx < ri; idx++) p[idx] = tmp[idx-le];

    return d;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);

    int n;
    cin>>n;
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    sort(p.begin(), p.end(), [](Point a, Point b) {
        return a.x < b.x;
    });

    cout << solve(0, n) << endl;

    return 0;
}