#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    
}
int main(){
    
}#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    ll ans=0;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n-1;i++){
        if(v[i]<v[i+1]){
            ans += (v[i+1]-(v[i]+1));
            v[i+1] = v[i]+1;
        }
    }

    for(int i=n-1;i>0;i--){
        if(v[i]<v[i-1]){
            ans += (v[i-1]-(v[i]+1));
            v[i-1] = v[i]+1;
        }
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}