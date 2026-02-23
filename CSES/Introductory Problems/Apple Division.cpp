#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int n;
ll ans = LONG_LONG_MAX;
void rec(int idx,ll l,ll r){
    if(idx>=n){
        ans = min(ans,abs(r-l));
        return;
    }
    rec(idx+1,l+v[idx],r);
    rec(idx+1,l,r+v[idx]);
}

int main(){
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    rec(0,0,0);
    cout << ans;
}