#include <bits/stdc++.h>
using namespace std;

int m_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_l(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int get_d(int y, int m, int d) {
    int res = 0;
    for (int i = 1; i < y; i++) {
        res += (is_l(i) ? 366 : 365);
    }
    for (int i = 1; i < m; i++) {
        res += m_days[i];
        if (i == 2 && is_l(y)) res++;
    }
    res += d;
    return res;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
        cout << abs(get_d(y1, m1, d1) - get_d(y2, m2, d2)) << '\n';
    }
}