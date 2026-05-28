#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    ll ans=0;
    while(pq.size()>1){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a+b);
        ans+=a+b;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}