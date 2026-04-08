#include <bits/stdc++.h>

using namespace std;

int num[25], t[25];

int main() {
    int n, a, b;
    if (!(cin >> n)) return 0;
    
    memset(num, 0, sizeof(num));
    memset(t, 0, sizeof(t));

    while (cin >> a >> b) {
        for (int i = 0; i < n; i++) {
            if (num[i] != 0) {
                t[i]--;
                if (t[i] <= 0) {
                    num[i] = 0;
                    t[i] = 0;
                }
            }
        }

        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == 0) {
                bool left_ok = (i == 0 || num[i - 1] == 0);
                bool right_ok = (i == n - 1 || num[i + 1] == 0);
                if (left_ok && right_ok) {
                    pos = i;
                    break;
                }
            }
        }

        if (pos == -1) {
            for (int i = 0; i < n; i++) {
                if (num[i] == 0) {
                    pos = i;
                    break;
                }
            }
        }
        if (pos == -1) {
            cout << "Not enough" << '\n';
        } else {
            num[pos] = a;
            t[pos] = b;
        }

        cout << "Number:";
        for (int i = 0; i < n; i++) cout << " " << num[i];
        cout << '\n';
        cout << "Time:";
        for (int i = 0; i < n; i++) cout << " " << t[i];
        cout << '\n' << '\n';
    }
}