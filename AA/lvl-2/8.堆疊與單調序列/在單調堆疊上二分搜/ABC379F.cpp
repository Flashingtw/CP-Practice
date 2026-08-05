#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<pii> q[N];
int h[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        q[l].push_back({r,i});
    }
    vector<int> ans(Q);
    vector<int> st;
    for(int i=n;i>=1;i--){
        for(auto [r,idx]:q[i]){
            ans[idx] = lower_bound(st.begin(),st.end(),r,greater())-st.begin();
        }
        while(!st.empty()&&h[i]>h[st.back()]){
            st.pop_back();
        }
        st.push_back(i);
    }
    for(int i:ans) cout << i << '\n';
}