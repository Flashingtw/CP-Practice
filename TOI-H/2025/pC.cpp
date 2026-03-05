#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans=0;
    unordered_map<ll,ll> mp;
    multiset<ll> s;
    for(int l=0,r=0;r<n;r++){
        mp[v[r]]++;
        s.insert(v[r]*mp[v[r]]);
        if(r-l==k-1){
            ans+= *s.rbegin();
            s.erase(s.lower_bound(v[l]*mp[v[l]]));
            mp[v[l]]--;
            l++;
        }
    }
    cout << ans;
}