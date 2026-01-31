#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin>>n;
    stack<pair<long long int,int>> st;
    long long int r=0;
    for (int i=0;i<n;i++) {
        long long int a;
        cin >> a;
        int c = 1;
        while (!st.empty()&& a > st.top().first) {
            r+=st.top().second;
            st.pop();
        }
        if (!st.empty() && a == st.top().first) {
            r += st.top().second;
            c += st.top().second;
            st.pop();
        }
        if (!st.empty()) {
            r++;
        }
        st.emplace(a,c);
    }
    cout << r*2 << endl;
}