#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll &i:a) cin>>i;
    for(ll &i:b) cin>>i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=0;
    int i=0,j=n-1,k=0,l=m-1;
    while(i<=j){
        if(abs(a[i]-b[l])>abs(a[j]-b[k])){
            ans+=abs(a[i]-b[l]);
            i++;l--;
        }
        else{
            ans+=abs(a[j]-b[k]);
            j--;k++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}