#include <bits/stdc++.h>
using namespace std;
struct MOU{
    int h, id;
    bool operator<(MOU &other){
        return h<other.h;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> v(n); 
    vector<MOU> sorted(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        sorted[i] = {v[i],i};
    }
    vector<int> L(n,-1),R(n,-1);
    stack<int> st;
    //left->right find left big
    for(int i=0;i<n;i++){
        while(!st.empty()&&v[st.top()]<=v[i]) st.pop();
        if(!st.empty()) L[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&v[st.top()]<=v[i]) st.pop();
        if(!st.empty()) R[i] = st.top();
        st.push(i);
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        if(L[i]!=-1) adj[L[i]].push_back(i);
        if(R[i]!=-1) adj[R[i]].push_back(i);
    }
    sort(sorted.begin(),sorted.end());
    vector<int> dp(n,1);
    int ans = 1;
    for(int i=0;i<n;i++){
        int u = sorted[i].id;
        for(int v:adj[u]){
            dp[u] = max(dp[u],1+dp[v]);
        }
        ans=max(ans,dp[u]);
    }
    cout << ans;
}