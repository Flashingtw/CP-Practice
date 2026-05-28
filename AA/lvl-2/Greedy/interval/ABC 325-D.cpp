#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<pll> v(n);
    for(auto &[l,r]:v) {
        ll a,b;
        cin>>a>>b;
        l = a;
        r = a+b;
    }
    sort(v.begin(),v.end());
    priority_queue<ll,vector<ll>,greater<>> pq;
    ll t=0;
    int cnt=0;
    int i=0;
    while(i<n||!pq.empty()){
        if(pq.empty()){
            t = v[i].first;
        }
        while(i<n&&v[i].first<=t){
            pq.push(v[i++].second);
        }
        while(!pq.empty()&&pq.top()<t){
            pq.pop();
        }
        if(!pq.empty()){
            pq.pop();
            cnt++;
            t++;
        }
    }
    cout << cnt << '\n';
}