#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    v.push_back(0);
    long long mx=0;
    stack<int> st;
    for(int i=0;i<n+1;i++){
        while(!st.empty()&&v[i]<v[st.top()]){
            long long h = v[st.top()];
            st.pop();
            long long w = (st.empty()?i:i-st.top()-1);
            mx=max(mx,h*w);
        }
        st.push(i);
    }
    cout << mx;
}