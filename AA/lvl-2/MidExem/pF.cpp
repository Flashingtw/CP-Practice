#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(ll &a:v) cin>>a;
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        int k=i+2;
        int l=i+2;
        for(int j=i+1;j<n;j++){
            k = max(k,j+1);
            while(k<n&&v[i]*v[i]+v[j]*v[j]>=v[k]*v[k]){
                k++;
            }
            while(l<n&&v[i]+v[j]>v[l]){
                l++;
            }
            ans+=(l-k);
        }
    }
    cout << ans << '\n';
}
