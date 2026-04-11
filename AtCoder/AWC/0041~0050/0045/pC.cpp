#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> diff(n+2);
    for(int i=0;i<k;i++){
        ll l,r,v;
        cin>>l>>r>>v;
        diff[l]+=v;
        diff[r+1]-=v;
    }
    ll cur=0;
    for(int i=1;i<=n;i++){
        cur+=diff[i];
        cout << cur << ' '; 
    }
}