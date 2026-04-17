#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
const int mod = 10000019;

ll rec(int l,int r,vector<ll> &v){
    if(l==r) return v[l];
    int mid = (l+r)/2;
    ll leftsum = rec(l,mid,v);
    rec(mid+1,r,v);
    vector<ll> tmp;
    int j = mid+1;
    for(int i=l;i<=mid;i++){
        while(j<=r&&v[j]<v[i]){
            ans = (ans+v[j]*(mid-i+1)+leftsum)%mod;
            tmp.push_back(v[j++]);
        }
        tmp.push_back(v[i]);
        leftsum-=v[i];
    }
    while(j<=r){
        tmp.push_back(v[j++]);
    }
    j = 0;
    ll sum=0;
    for(int i=l;i<=r;i++){
        v[i]=tmp[j++];
        sum+=v[i];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    rec(1,n,v);
    cout << ans << '\n';
}