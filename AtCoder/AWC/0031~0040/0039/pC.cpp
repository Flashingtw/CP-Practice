#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int l=0;
    ll cur=0,ans=0,sat=0;
    for(int r=0;r<n;r++){
        cur+=b[r];
        sat+=a[r];

        while(cur>k){
            cur-=b[l];
            sat-=a[l];
            l++;
        }
        ans = max(ans,sat);
    }
    cout << ans << '\n';
}