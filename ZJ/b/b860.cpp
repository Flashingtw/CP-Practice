#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, w;
    cin >> c >> w;

    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        if (w > 0 && c >= 12) {
            c -= 12;
            w -= 1;
            ans++;
            c += 2;
        } else if (w > 1 && c < 12) {
            int need = 12 - c;
            int sell = w - 1;
            if (sell >= need) {
                w -= need;
                c += need;
            } else {
                break;
            }
        } else {
            break;
        }
    }

    cout << ans << '\n';
}