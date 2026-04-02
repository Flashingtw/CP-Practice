#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
int main(){
    int n,q;
    cin>>n>>q;
    vector<pii> v(n+1);
    for(int i=1;i<=n;i++){
        int y,p;
        cin>>y>>p;
        v[i]={y,p};
    }
    sort(v.begin()+1,v.end());
    vector<ll> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+v[i].second;
    }
    while(q--){
        ll l;
        cin>>l;
        auto it = upper_bound(v.begin()+1,v.end(),make_pair(l,-1LL));
        it--;
        int idx = it-v.begin();
        cout << pre[n]-pre[idx] << '\n';
    }
}