#include <iostream>
#include <stack>
using namespace std;
int main() {
    string n;
    while (cin>>n) {
        stack<int> st;
        int num=0;
        char sync = '+';
        n+='+';
        for (int i=0;i<n.length();i++) {
            char c = n[i];
            if (isdigit(c)) {
                num = num*10 +  c-'0';
            }
            if (!isdigit(c)) {
                if (sync=='+') st.push(num);
                if (sync=='-') st.push(-num);
                if (sync=='*') {
                    int top = st.top();
                    st.pop();
                    st.push(top*num);
                }
                if (sync=='/') {
                    int top = st.top();
                    st.pop();
                    st.push(top/num);
                }
                sync=c;
                num=0;
            }
        }
        int sum=0;
        while (!st.empty()) {
            sum+=st.top();
            st.pop();
        }
        cout << sum << "\n";
    }
}
