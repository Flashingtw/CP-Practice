#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, m;
    for (;;) {
        if (!(cin >> h >> m)) break;

        m += 30;
        h += 2;

        if (m >= 60) {
            m -= 60;
            h += 1;
        }

        if (h >= 24) {
            h %= 24;
        }

        cout << setfill('0') << setw(2) << h << ":" 
             << setfill('0') << setw(2) << m << '\n';
        
        break;
    }
}