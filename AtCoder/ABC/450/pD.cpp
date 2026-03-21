#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n),c;
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    for(int i=0;i<n;i++){
        int mul = (mx-a[i])/k +1;
        c.push_back(a[i]+k*mul);
    }

    sort(c.begin(),c.end());
    ll ans = c[n-1]-c[0];
    for(int i=0;i<n-1;i++){
        ans = min(ans,c[i]+k-c[i+1]);
    }
    cout << ans;
}