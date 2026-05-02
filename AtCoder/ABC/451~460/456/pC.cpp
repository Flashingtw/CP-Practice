#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
int main(){
    string s;
    cin>>s;
    int n = s.length();
    int l=0,r = 1;
    //[l,r)
    ll ans = 0;
    while(l<n){
        r = l+1;
        while(r<n&&s[r]!=s[r-1]){
            r++;
        }
        ll len = r-l;
        ans = (ans+len*(len+1)/2)%mod;
        l = r;
    }
    cout << ans << '\n';
}