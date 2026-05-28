#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int mod = 1000007;

ll f[100005];

void pre(){
    f[0]=1;
    f[2] = 3;
    for(int i=4;i<=100000;i+=2){
        f[i] = ((4*f[i-2])%mod-f[i-4]+mod)%mod;
    }
}

void solve(){
    int N;
    cin>>N;
    if(N&1) {
        cout << 0 << '\n';
        return;
    }
    cout << f[N] << '\n';
}
int main(){
    pre();
    int t;
    cin>>t;
    while(t--) solve();
}