#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main(){
    int n,m;
    cin>>n>>m;
    ll sum_n=0,sum_m=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        sum_n = (sum_n+num)%mod;
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        sum_m = (sum_m+num)%mod;
    }
    ll ans = abs(((sum_n*m)%mod-(sum_m*n)%mod));
    cout << ans;
}