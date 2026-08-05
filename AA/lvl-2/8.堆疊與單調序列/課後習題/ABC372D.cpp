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
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> st,ans(n+1);
    for(int i=n;i>=1;i--){
        ans[i] = st.size();
        while(!st.empty()&&v[i]>v[st.back()]){
            st.pop_back();
        }
        st.push_back(i);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
}