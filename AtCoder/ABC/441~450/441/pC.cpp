#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll sum=0,cnt=0;
    for(int i=k-1;i>=0;i--) {
        sum+=v[i];
        cnt++;
        if(sum>=x) break;
    }
    if(sum<x){
        cout << -1 << '\n';
    }
    else{
        cout << (n-k)+cnt;
    }
}