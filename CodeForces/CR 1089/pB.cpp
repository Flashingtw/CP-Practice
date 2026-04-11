#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n+1),mk(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pos[v[i]]=i;
    }
    int ans=0,a=0,b=0;
    for(int i=1;i<=n;i++){
        if(v[i]<=i){
            a++;
        }
        else{
            b++;
        }
        if(pos[i]<i) b--;
        ans = max(ans,a+b);
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}