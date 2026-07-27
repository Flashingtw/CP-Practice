#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll n,k;
bool chk(ll tar,vector<ll> a){
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+= min(a[i],tar);
    }
    return sum<=k;
}
int main(){
    cin>>n>>k;
    vector<ll> a(n),org(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        org[i]=a[i];
    }
    ll l = 0,r = 1e12,ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,a)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    ll used=0;
    for(int i=0;i<n;i++){
        org[i] = a[i]-min(a[i],ans);
        used += min(a[i],ans);
    }
    ll diff = k-used;
    for(int i=0;i<n;i++){
        if(org[i]>0&&diff>0){
            org[i]--;
            diff--;
        }
        cout << org[i] << ' ';
    }
}