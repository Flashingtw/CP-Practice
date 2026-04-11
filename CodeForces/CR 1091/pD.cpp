#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+2),d(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> pos(k);
    for(int i=0;i<k;i++){
        cin>>pos[i];
    }
    int x = v[pos[0]];
    v[0]=x,v[n+1]=x;
    for(int i=0;i<=n;i++){
        if(v[i]!=v[i+1]){
            d[i]=1;
        }
        else d[i]=0;
    }
    vector<int> ans(k+1);
    int j=0,s=0;
    for(int i=0;i<=n;i++){
        if(j<k&&i>=pos[j]) j++;
        if(d[i]==1){
            ans[j]++;
            s++;
        }
    }
    int mx = *max_element(ans.begin(),ans.end());
    cout << max(mx,s/2) << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}