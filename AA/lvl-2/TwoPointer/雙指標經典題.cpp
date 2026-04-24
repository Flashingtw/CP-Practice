#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int j=1;
    ll ans=0;
    for(int i=0;i<n;i++){
        while(j<n&&v[i]+s>=v[j]){
            j++;
        }
        ans+= j-i-1;
    }
    cout << ans << '\n';
}