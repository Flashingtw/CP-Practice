#include <iostream>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}