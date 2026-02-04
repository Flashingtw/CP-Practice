#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n,l;
    cin>>n>>l;
    vector<int> p(n+2),h(n+2);
    p[0] = 0;
    p[n+1] = l;
    h[0] = 1000000000;
    h[n+1] = 1000000000;
    for (int i=1;i<=n;i++) cin>> p[i];
    for (int i=1;i<=n;i++) cin>> h[i];
    stack<int> st;
    st.push(0);
    int total=0,high=0;
    for (int i=1;i<=n;i++) {
        if (p[i]-h[i]>=p[st.top()]||p[i]+h[i]<=p[i+1]) {
            total++;
            high = max(high,h[i]);
            while (p[st.top()]+h[st.top()]<=p[i+1]) {
                total++;
                high = max(high,h[st.top()]);
                st.pop();
            }
        }
        else {
            st.push(i);
        }
    }
    cout << total << "\n" << high;
}