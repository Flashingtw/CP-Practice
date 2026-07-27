#include <iostream>
#include <stack>
using namespace std;
int main() {
    string n;
    while (cin>>n) {
        stack<char> st;
        for (int i=0;i<n.length();i++) {
            bool b=true;
            if (!st.empty()) {
                if (n[i]=='}'&&st.top()=='{') b=false;
                if (n[i]==']'&&st.top()=='[') b=false;
                if (n[i]==')'&&st.top()=='(') b=false;
                if (b) st.push(n[i]);
                else st.pop();
            }
            else {
                st.push(n[i]);
            }
        }
        cout << (st.empty()?"yes":"no")<< "\n";
    }
}