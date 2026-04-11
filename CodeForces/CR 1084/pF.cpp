#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> a(n),shop(m);
    for(int i=0;i<n;i++) cin>>a[i].second>>a[i].first;
    for(int i=0;i<m;i++) cin>>shop[i].second>>shop[i].first;
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(a.rbegin(),a.rend());
    vector<ll> f(n+2,-1e18),g(n+2,-1e18);
    ll sum=0;
    for(int S=n+1,i=0;S>=1;S--){
        while(i<n&&a[i].first>=S-1){
            pq.push(a[i].second);
            sum+=a[i].second;
            i++;
        }
        while(pq.size()>S){
            sum-=pq.top();
            pq.pop();
        }
        if(pq.size()==S) {
            f[S]=sum;
            g[S]=sum-pq.top();
        }
        else if (pq.size()==S-1){
            g[S]=sum;
        }
    }
    ll base_ans=0;
    for(int i=1;i<=n+1;i++) base_ans=max(base_ans,f[i]);
    for(int i=1;i<=n+1;i++) g[i] = max(g[i],g[i-1]);
    for(auto [x,y]:shop){
        cout << max(y+g[min(n+1,x+1)],base_ans) << ' ';
    }
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}