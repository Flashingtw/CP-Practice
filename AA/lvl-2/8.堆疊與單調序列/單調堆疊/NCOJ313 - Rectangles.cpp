#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
char g[5005][5005];
int top[5005][5005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>g[i][j];
    ll ans=0;
    for(int i=1;i<=n;i++){
        stack<int> st;
        st.push(0);
        ll cur=0;
        for(int j=1;j<=n;j++){
            if(g[i][j]=='#') top[i][j]=0;
            else top[i][j] = top[i-1][j]+1;
            while(top[i][j]<top[i][st.top()]){
                int a=st.top();
                st.pop();
                cur-=(a-st.top())*top[i][a];
            }
            cur+=(j-st.top())*top[i][j];
            ans+=cur;
            st.push(j);
        }
    }
    cout << ans << '\n';
}