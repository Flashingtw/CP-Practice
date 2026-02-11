#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    ll ans=0,cur=0;
    for(auto [time,end]:v){
        cur+=time;
        ans+= end-cur;
    }
    cout << ans;
}