#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    ll sum=0;
    for(ll i=1;i<=n;i++) {
        cin>>v[i];
        sum+= i*(n-i+1)*v[i];
    }
    while(q--){
        ll a,x;
        cin>>a>>x;
        sum -= a*(n-a+1)*v[a];
        sum += a*(n-a+1)*x;
        v[a] = x;
        cout << sum << '\n';
    }
}