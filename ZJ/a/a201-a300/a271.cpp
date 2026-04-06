#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z, w, n, m;
        cin >> x >> y >> z >> w >> n >> m;
        string s;
        getline(cin, s);
        getline(cin, s);
        
        stringstream ss(s);
        int d;
        long long poison_cnt = 0;
        bool dead = false;

        while (ss >> d) {
            m -= poison_cnt * n;
            if (m <= 0) {
                dead = true;
                break;
            }

            if (d == 1) m += x;
            else if (d == 2) m += y;
            else if (d == 3) m -= z;
            else if (d == 4) {
                m -= w;
                poison_cnt++;
            }

            if (m <= 0) {
                dead = true;
                break;
            }
        }

        if (dead) cout << "bye~Rabbit" << '\n';
        else cout << m << "g" << '\n';
    }
}