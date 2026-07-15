#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1);
    v[0]=0;
    stack<int> st;
    st.push(0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        while(v[st.top()]>=v[i]) st.pop();
        cout << st.top() << ' ';
        st.push(i);
    }
}