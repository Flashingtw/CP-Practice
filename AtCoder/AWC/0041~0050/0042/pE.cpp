#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e18+9;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<ll> v(n+1);
    vector<ll> prefix(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+v[i];
    }
    deque<ll> dqw,dqr;
    vector<ll> w(n+1,-INF),r(n+1,-INF);
    r[0]=0,w[0]=0;
    dqw.push_back(0),dqr.push_back(0);
    for(int i=1;i<=n;i++){
        while(!dqr.empty()&&i-dqr.front()>=m){
            dqr.pop_front();
        }
        r[i] = w[dqr.front()];
        while(!dqw.empty()&&i-dqw.front()>=k){
            dqw.pop_front();
        }
        w[i] = prefix[i] + (r[dqw.front()] - prefix[dqw.front()]);

        while(!dqr.empty()&&w[i]>=w[dqr.back()]){
            dqr.pop_back();
        }
        while(!dqw.empty()&&r[i] - prefix[i]>=r[dqw.back()]-prefix[dqw.back()]){
            dqw.pop_back();
        }
        dqr.push_back(i);
        dqw.push_back(i);
    }
    ll ans = max(w[n],r[n]);
    if(ans==-INF) cout << -1;
    else cout << ans;
}
