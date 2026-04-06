#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans;
    int a[3], b[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    cin >> n;
    for (int i = 0; i <= n; i++) {
        int c = i;
        int d = n - i;
        int o1 = a[0] * c * c + a[1] * c + a[2];
        int o2 = b[0] * d * d + b[1] * d + b[2];
        if (i == 0)
            ans = o1 + o2;
        else if (o1 + o2 > ans)
            ans = o1 + o2;
    }
    cout << ans << endl;
}