#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> st={0};
    ll ans=0;
    for(int i=1;i<=n+1;i++){
        while(st.size()>1&&a[i]<a[st.back()]){
            ll h = a[st.back()];
            st.pop_back();
            ans = max(ans,(i-st.back()-1LL)*h);
        }
        st.push_back(i);
    }
    cout << ans << '\n';
}