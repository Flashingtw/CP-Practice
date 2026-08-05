#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int h[N],p[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    
    vector<int> st = {0};
    vector<int> st_v = {(int)(2e9+9)};
    h[0]=2e9+9;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int ridx = (upper_bound(st_v.rbegin(),st_v.rend(),h[i]+p[i])-st_v.rbegin());
        int idx = st.size()-ridx-1;
        ans+=1LL*(i-(st[idx])-1);
        while(!st.empty()&&h[i]>=h[st.back()]){
            st.pop_back();
            st_v.pop_back();
        }
        st.push_back(i);
        st_v.push_back(h[i]);
    }
    cout << ans << '\n';
}