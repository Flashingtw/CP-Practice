#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> h(n+1,0),p(n+1,0);
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>p[i];
    vector<int> st;
    long long sum=0;
    for (int i=1;i<=n;i++) {
        while (!st.empty()&&h[st.back()]<=h[i]) {
            st.pop_back();
        }
        long long target = (long long)h[i]+p[i];
        int index = 0;
        if (!st.empty()) {
            int L=0,R=st.size()-1;
            int best = -1;
            while (L<=R) {
                int mid = (L+R)/2;
                if (h[st[mid]]>target) {
                    best = mid;
                    L = mid+1;
                }
                else {
                    R=mid-1;
                }
            }
            if (best!=-1) {
                index=st[best];
            }
        }
        sum+= i-index-1;
        st.push_back(i);
    }
    cout << sum << " ";
}