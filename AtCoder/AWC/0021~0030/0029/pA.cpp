#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,p,b,k;
    cin>>n>>p>>b>>k;
    ll ans=0;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        ll diff = c*p;
        if(c>=k){
            diff = c*(p+b);
        }
        ans+= diff;
    }
    cout << ans;
}