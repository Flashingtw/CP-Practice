#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> A(n),B(m),prefix(n+1);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    prefix[0] = 0;
    for(int i=1;i<=n;i++){
        prefix[i]=(prefix[i-1]+A[i-1])%mod;
    }
    ll left=0,right=0,left_diff=0,right_diff=0;
    for(int i=0;i<m;i++){
        ll num;
        cin>>num;
        int idx = lower_bound(A.begin(),A.end(),num)-A.begin();
        left = (left+ (num*idx)%mod-prefix[idx]+mod)%mod;
        right = (right+ (prefix[n]-prefix[idx]+mod)%mod-num*(n-idx)%mod +mod)%mod;
    }
    cout << (left+right)%mod;
}