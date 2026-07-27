#include <bits/stdc++.h>
using namespace std;
const int N = 1000005; // 1e6 + 5
int n;
int h[N];
long long v[N];
struct node{
    int h;
    long long val;
    long long sum;
};
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    h[n]=1e9+9;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    v[n]=0;
    stack<node> st;
    for(int i=0;i<=n;i++){
        long long dp = 0;
        while(!st.empty()&&st.top().h<=h[i]){
            node temp = st.top();
            st.pop();
            if(temp.h==h[i]){
                v[i]= max(v[i],temp.val);
                dp+=temp.sum;
            }
            else{
                dp = max(temp.val,temp.sum+dp);
            }
        }
        st.push({h[i],v[i],dp});
    }
    cout << st.top().sum << "\n";
}