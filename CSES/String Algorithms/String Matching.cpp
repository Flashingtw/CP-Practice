#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
const int P = 13331;
const int mod = 1e9+7;
ll powP[N];
ll h[N];
//98765 get 876 -> 9876-9000
ll solve(int L,int R) {
    ll result = h[R];//98765
    if (L>0) {
                //98765-98*10^(4-2+1)-> 98765-98000 = 765
        ll sub = h[L-1]*powP[R-L+1]%mod;
        result  = (result-sub+mod)%mod;
    }
    return result;
}

int main() {
    string t,p;
    cin>>t>>p;
    int n = t.length(),m=p.length();
    powP[0] = 1;
    for (int i=1;i<=n;i++) {
        powP[i]=(powP[i-1]*P)%mod;
    }
    h[0] = t[0];
    for (int i=1;i<n;i++) {
        h[i] = (h[i-1]*P+t[i])%mod;
        //like 32 = 3*10+2
    }
    ll target=0;
    for (int i=0;i<m;i++) {
        target = (target*P+p[i])%mod;
    }
    int cnt=0;
    for (int i=0;i<=n-m;i++) {
        if (solve(i,i+m-1)==target) {
            cnt++;
        }
    }
    cout << cnt;
}