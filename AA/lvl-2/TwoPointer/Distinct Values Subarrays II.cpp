#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &a:v) cin>>a;
    
    ll ans=0;
    ll l = 0;
    map<int,int> cnt;
    int chk=0;
    for(ll r=0;r<n;r++){
        if(cnt[v[r]]==0) chk++;
        cnt[v[r]]++;
        while(chk>k){
            if(cnt[v[l]]==1) chk--;
            cnt[v[l++]]--;
        }

        ans += r-l+1;
    }
    cout << ans << '\n';
}