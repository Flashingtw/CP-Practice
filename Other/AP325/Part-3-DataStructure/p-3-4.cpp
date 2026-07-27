#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    stack<int> st;
    int n;
    cin>>n;
    vector<int> v(n+1);
    long long sum=0;
    for (int i=1;i<=n;i++) {
        int num;
        cin>>num;
        v[i]=num;
        while (!st.empty()&&v[st.top()]<=num) {
            st.pop();
        }
        sum += st.empty()?i:i-st.top();
        st.push(i);
    }
    cout << sum;
}