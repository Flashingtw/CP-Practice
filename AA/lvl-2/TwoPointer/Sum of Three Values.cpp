#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll t = x-v[i].first-v[j].first;
            pii a = {t,-1};
            ll pos = lower_bound(v.begin()+j+1,v.end(),a) - v.begin();
            if(pos<n&&v[pos].first==t){
                cout << v[i].second << ' ' << v[j].second << ' ' << v[pos].second;
                return 0; 
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}