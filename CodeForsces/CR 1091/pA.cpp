#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        sum+=a;
    }
    ll t = k*n;
    if(sum&1){
        cout << "Yes\n";
    }
    else{
        if(t&1){
            cout << "No\n";
        }
        else cout << "Yes\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}