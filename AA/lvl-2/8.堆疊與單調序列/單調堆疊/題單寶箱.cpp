#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1.5e6+5;
int a[N];
ll ans[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> st = {0};
    for(int i=1;i<=n+1;i++){
        while(a[i]<a[st.back()]){
            ans[a[st.back()]]+= ans[a[st.back()]]*(i-st.back()-1);
            st.pop_back();
        }
        ans[a[i]]=i-st.back();
        st.push_back(i);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=i*ans[i];
    }
    cout << cnt << '\n';
}