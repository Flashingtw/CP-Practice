#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,t;
    cin>>n>>t;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a,c;
        cin>>a>>c;
        if(a<t){
            ans+= (t-a)*c;
        }
    }
    cout << ans;
}