#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a+b==0){
            continue;
        }
        if((a+b)%k==0){
            ans+=(a+b)/k;
        }
        else ans+= (a+b)/k+1;
    }
    cout << ans;
}