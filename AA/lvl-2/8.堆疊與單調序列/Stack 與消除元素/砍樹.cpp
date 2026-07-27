#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    ll L;
    cin>>n>>L;
    vector<pll> v(n+2);
    v[0] = {0,2e9};
    v[n+1] = {L,2e9};
    for(int i=1;i<=n;i++) cin>>v[i].first;
    for(int i=1;i<=n;i++) cin>>v[i].second;
    vector<pll> st;
    ll hi=0;
    int cnt=0;
    for(auto [p,h]:v){
        while(!st.empty()&&st.back().first+st.back().second<=p){
            cnt++,hi=max(hi,st.back().second);
            st.pop_back();
        }
        if(st.empty()||p-h<st.back().first) st.push_back({p,h});
        else cnt++,hi=max(hi,h);
    }
    cout << cnt << '\n' << hi << '\n';
}