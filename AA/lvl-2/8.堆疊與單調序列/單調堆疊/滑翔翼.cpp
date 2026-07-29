#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    vector<int> st;
    ll ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty()&&v[i]>v[st.back()]){
            ans+= i-st.back();
            st.pop_back();
        }
        if (!st.empty()) {
            ans+= i-st.back();
            if(v[i]==v[st.back()]) st.pop_back();
        }
        st.push_back(i);
    }
    cout << ans << '\n';
}