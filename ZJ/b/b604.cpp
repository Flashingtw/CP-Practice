#include <bits/stdc++.h>
using namespace std;

struct P {
    long long x, y;
};

bool cmp(P a, P b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<P> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }
        
        sort(p.begin(), p.end(), cmp);
        
        long long targetX = p[0].x + p[n - 1].x;
        long long targetY = p[0].y + p[n - 1].y;
        
        bool ok = true;
        for (int i = 0; i < n / 2 + (n % 2); i++) {
            if (p[i].x + p[n - 1 - i].x != targetX || p[i].y + p[n - 1 - i].y != targetY) {
                ok = false;
                break;
            }
        }
        
        if (ok) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}