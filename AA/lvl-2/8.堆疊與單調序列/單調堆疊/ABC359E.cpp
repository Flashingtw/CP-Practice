#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll ans[N];
ll a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> st={0};
    ans[0]=1;
    a[0]=2e9;
    for(int i=1;i<=n;i++){
        while(a[i]>=a[st.back()]){
            st.pop_back();
        }
        ans[i] = ans[st.back()]+(a[i]*(i-st.back()));
        st.push_back(i);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
}