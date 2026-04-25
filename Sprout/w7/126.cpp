#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int mod = 1000007;
const int N = 100005;

ll ans[N];

void solve(){
    int n;
    cin>>n;
    cout << ans[n] << '\n';
}

void pre1(){//red start
    vector<ll> R(N),G(N),B(N);
    R[1]=1,G[1]=0,B[1]=0;
    ans[1] = 3;
    for(int i=2;i<=100000;i++){
        R[i] = (R[i-1]+G[i-1]+B[i-1])%mod;
        G[i] = (R[i-1]+G[i-1])%mod;
        B[i] = (R[i-1]+B[i-1])%mod;
        ans[i] = (ans[i]+R[i]+G[i]+B[i])%mod;
    }
}

void pre2(){
    vector<ll> R(N),G(N),B(N);
    R[1]=0,G[1]=1,B[1]=0;
    for(int i=2;i<=100000;i++){
        R[i] = (R[i-1]+G[i-1]+B[i-1])%mod;
        G[i] = (R[i-1]+G[i-1])%mod;
        B[i] = (R[i-1]+B[i-1])%mod;
        ans[i] = (ans[i] + 2*(R[i]+G[i]))%mod;
    }
}

int main(){
    pre1();
    pre2();
    int t;
    cin>>t;
    while(t--) solve();
}