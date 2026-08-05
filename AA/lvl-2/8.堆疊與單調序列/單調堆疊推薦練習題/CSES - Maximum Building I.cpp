#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
char g[1005][1005];
int a[1005][1005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=1;i<=n;i++){
        vector<int> st = {0};
        a[i-1][m+1] = -1;
        for(int j=1;j<=m+1;j++){
            if(j<=m) cin>>g[i][j];
            if(g[i][j]=='*') a[i][j]=0;
            else a[i][j] = a[i-1][j]+1;
            while(!st.empty()&&a[i][j]<a[i][st.back()]){
                int h = a[i][st.back()];
                st.pop_back();
                ans = max(ans,(j-st.back()-1)*1LL*h);
            }
            st.push_back(j);
        }
    }
    cout << ans << '\n';
}