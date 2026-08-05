#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int INF = 1e9+9;
ll f(ll L,int x){
    ll a = L/x;//length
    // L%x a+1
    // a-(L%x) a
    ll less = x-(L%x);
    return (less*a*a)+((L%x)*(a+1)*(a+1));
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    priority_queue<pii> pq;
    ll ans=0;
    for(ll cnt=0;ll &i:v) {
        cin>>i;
        pq.push({f(i,1)-f(i,2),cnt++});      
        ans+=f(i,1);
    }
    vector<int> cur(n,1);
    for(int i=0;i<k-n;i++){
        auto [a,idx] = pq.top();
        pq.pop();
        ans-=a;
        cur[idx]++;
        pq.push({f(v[idx],cur[idx])-f(v[idx],cur[idx]+1),idx});
    }
    cout << ans << '\n';
}