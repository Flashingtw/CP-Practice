#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    bool isValid = true;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{'|| c == '<') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                isValid = false;
                break;
            }
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{') ||
                (c == '>' && top == '<') ) {
                st.pop();
            } else {
                isValid = false;
                break;
            }
        }
    }
    if (isValid && st.empty()) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}
int main() {
    int n;
    cin>>n;
    while (n--) {
        solve();
    }
}
