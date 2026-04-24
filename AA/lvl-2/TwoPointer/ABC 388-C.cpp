#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int j=1;
    ll ans=0;
    for(int i=0;i<n;i++){
        while(j<n&&v[i]*2>v[j]){
            j++;
        }
        ans+= n-j;
    }
    cout << ans << '\n';
}