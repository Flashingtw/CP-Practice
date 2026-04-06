#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int l, r;
};

bool cmp(Seg a, Seg b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

int main() {
    int n;
    cin >> n;

    vector<Seg> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end(), cmp);

    int ans = 0;
    int curL = -1, curR = -1;

    for (int i = 0; i < n; i++) {
        if (a[i].l > curR) {
            ans += (curR - curL);
            curL = a[i].l;
            curR = a[i].r;
        } else {
            if (a[i].r > curR) {
                curR = a[i].r;
            }
        }
    }
    
    ans += (curR - curL);
    
    if (curL != -1) {
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
}