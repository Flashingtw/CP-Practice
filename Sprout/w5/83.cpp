#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    string s;
    cin>>n;
    if(n==1) cout << 1 << '\n';
    if(n==0) cout << 0 << '\n';
    if(n<=1) return;
    for(int i=9;i>=2;i--){
        while(n%i==0){
            s.push_back(i+'0');
            n/=i;
        }
    }
    reverse(s.begin(),s.end());
    if(n==1){
        cout << s << '\n';
    }
    else cout << -1 << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}