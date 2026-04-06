#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int cnt[26] = {0};
        for (char c : s) {
            if (isalpha(c)) {
                cnt[tolower(c) - 'a']++;
            }
        }
        
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 != 0) odd++;
        }
        
        if (odd <= 1) cout << "yes !" << '\n';
        else cout << "no..." << '\n';
    }
}