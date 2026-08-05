#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
vector<pii> Q[N];
int h[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>h[i];
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        Q[l].push_back({r,i});
    }
    vector<int> st;
    for(int i=n;i>=1;i--){
        while(!st.empty()&&h[i]>=h[st.back()]){
            st.pop_back();
        }
        st.push_back(i);
        for(auto [r,idx]:Q[i]) ans[idx] = (upper_bound(st.rbegin(),st.rend(),r)-st.rbegin());
    }
    for(int i:ans){
        cout << i << '\n';
    }
}