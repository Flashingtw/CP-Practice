#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,l,r;
    cin>>n>>l>>r;
    int d = r-l;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        a[i] = a[i-1]+x;
    }
    deque<int> dq;
    ll ans=-1e18;
    for(int i=0;i<=n-l;i++){
        while(!dq.empty()&&i-dq.front()>d) dq.pop_front();
        while(!dq.empty()&&a[i]<a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        ans = max(ans, a[i+l]-a[dq.front()]);
    }
    cout << ans << '\n';
}