#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int N;
    ll K, M;
    cin >> N >> K >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    ll current_sum = 0;
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && (current_sum < M || (r - l) < K)) {
            current_sum += A[r];
            r++;
        }
        if (current_sum >= M && (r - l) >= K) {
            ans += (ll)(N - r + 1);
        }
        if (r > l) {
            current_sum -= A[l];
        } else {
            r++; 
        }
    }

    cout << ans << endl;

    return 0;
}