#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(v[i]<=v[i+1]) cnt++; 
    }
    if(cnt==n-1) cout << n << '\n';
    else cout << 1 << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}