#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<pll> st;
    st.push_back({1,n});
    while(q--){
        ll a;
        cin>>a;

        ll ans=st.back().first-1;
        st.back().first+=1;
        st.back().second-=1;
        if(st.back().second<=0) st.pop_back();

        ll need = a;
        ll cur = 1;
        while(need){
            ll cost = min(st.back().second,need);
            ans+= (st.back().first-cur)*cost;
            cur+=cost;
            need-=cost;
            st.back().first+=cost;
            st.back().second-=cost;
            if(st.back().second<=0) st.pop_back();
        }
        if(a>0) st.push_back({1,a});
        cout << ans << ' ';
    }
}