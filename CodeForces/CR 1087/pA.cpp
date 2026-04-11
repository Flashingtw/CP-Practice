#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(a[i]<=c){
            if(k>=(c-a[i])){
                k-=(c-a[i]);
                c*=2;
            }
            else {
                c+=k+a[i];
                k=0;
            }
        }
        else break;
    }
    cout << c << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}