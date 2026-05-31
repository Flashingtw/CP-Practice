#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,q,t;
    cin>>n>>q>>t;
    vector<ll> L;
    vector<ll> R;
    L.reserve(n),R.reserve(n);
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        if(r-l>=t){
            L.push_back(l);
            R.push_back(r-t);
        }
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    int val = L.size();
    while(q--){
        ll ql,qr,x;
        cin>>ql>>qr>>x;
        if(qr-ql<t){
            cout << "No" << '\n';
            continue;
        }
        ll mx = qr-t;
        ll mn = ql;
        ll late = L.end() - upper_bound(L.begin(),L.end(),mx);
        ll ear = lower_bound(R.begin(),R.end(),mn) - R.begin();
        ll ava = val-late-ear;
        if(ava>=x) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}