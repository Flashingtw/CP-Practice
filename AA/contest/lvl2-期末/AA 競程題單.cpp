#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
int a[N],ans[N],n;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) ans[i]=INF;
    vector<pii> st;
    for(int i=0;i<n;i++){
        int l=i;
        while(!st.empty()&&a[i]>=st.back().first){
            ans[i-st.back().second] = min(ans[i-st.back().second],st.back().first);
            l = st.back().second;
            st.pop_back();
        }
        st.push_back({a[i],l});
    }
    while(!st.empty()){
        ans[n-st.back().second] = min(ans[n-st.back().second],st.back().first);
        st.pop_back();
    }
    int mn=INF;
    for(int i=n;i>0;i--){
        mn = min(mn,ans[i]);
        ans[i] = mn;
    }
    int q;
    cin>>q;
    while(q--){
        int d;
        cin>>d;
        cout << ans[d] << '\n';
    }
}