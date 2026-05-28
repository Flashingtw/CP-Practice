#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    bitset<20005> dp;
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        int c, k;
        cin >> c >> k;
        
        for (int p = 1; p <= k; p *= 2) {
            int w = p * c;
            dp |= (dp << w);
            k -= p;
        }
        if (k > 0) {
            int w = k * c;
            dp |= (dp << w);
        }
    }

    if (dp[M]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}