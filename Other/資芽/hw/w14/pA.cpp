#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computePi(const string& s) {
    int m = s.length();
    vector<int> pi(m, 0);
    int j = 0;
    
    for (int i = 1; i < m; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);

    string S, T;
    cin >> S >> T;

    int m = S.length();
    int n = T.length();

    vector<int> pi = computePi(S);
    vector<int> matches;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != S[j]) {
            j = pi[j - 1];
        }
        if (T[i] == S[j]) {
            j++;
        }
        if (j == m) {
            matches.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    for (size_t i = 0; i < matches.size(); i++) {
        cout << matches[i];
        if (i + 1 < matches.size()) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}