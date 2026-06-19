#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    if (!(cin >> n >> k >> q)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int MAX_VAL = 500005;
    vector<vector<uint64_t>> weights(MAX_VAL);
    vector<int> current_count(MAX_VAL, 0);
    vector<uint64_t> current_block_xor(MAX_VAL, 0);

    mt19937_64 rng(1337);

    vector<uint64_t> pref_xor(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int v = a[i];
        int idx = current_count[v] % k;
        
        if (weights[v].size() <= idx) {
            if (k == 1) {
                weights[v].push_back(0);
            } else if (idx < k - 1) {
                uint64_t w = rng();
                weights[v].push_back(w);
                current_block_xor[v] ^= w;
            } else {
                weights[v].push_back(current_block_xor[v]);
            }
        }
        
        uint64_t w = weights[v][idx];
        pref_xor[i + 1] = pref_xor[i] ^ w;
        current_count[v]++;
    }

    string ans = "";
    ans.reserve(q);
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if ((pref_xor[r] ^ pref_xor[l - 1]) == 0) {
            ans += '1';
        } else {
            ans += '0';
        }
    }

    cout << ans << "\n";

    return 0;
}