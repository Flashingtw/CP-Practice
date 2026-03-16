#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (is_sorted(s.begin(), s.end())) {
            cout << "Bob\n";
            continue;
        }
        cout << "Alice\n";
        int cnt0 = 0;
        for(char c : s) if (c=='0') cnt0++;
        vector<int> m;
        for (int i=0;i<n;i++) {
            if (i<cnt0&&s[i]=='1') m.push_back(i+1);
            if (i>=cnt0&&s[i]=='0') m.push_back(i+1);
        }
        cout << m.size() << "\n";
        for (int i : m) cout << i << " ";
        cout << "\n";
    }
}