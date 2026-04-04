#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    ll suma=0,sumb=0;
    for(int i=1;i<=n;i++){
        suma = (suma + (a[i]*i)%mod)%mod;
    }
    for(int j=1;j<=m;j++){
        sumb = (sumb+b[j])%mod;
    }
    ll left = (suma*sumb)%mod;

    vector<ll> prefix(n+1);
    for(int i=1;i<=n;i++){
        prefix[i] = (prefix[i-1]+a[i])%mod;
    }
    ll right=0;
    for(int j=1;j<=m;j++){
        ll B = (b[j]*j)%mod,A=0;
        for(int k=1;k<=n/j;k++){
            int l = k*j,r = min(n,(k+1)*j-1);
            A = (A + k*(prefix[r]-prefix[l-1]+mod)%mod)%mod;
        }
        right = (right+B*A)%mod;
    }
    cout << (left-right+mod)%mod;
}