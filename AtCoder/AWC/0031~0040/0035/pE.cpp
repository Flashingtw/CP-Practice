#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    stack<int> st;
    ll ans=0;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        while(!st.empty()&&st.top()<=a) st.pop();
        if(!st.empty()) ans+=st.size();
        st.push(a);
    }
    cout << ans;
}