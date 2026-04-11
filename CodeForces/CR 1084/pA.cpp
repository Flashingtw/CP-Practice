#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int cnt=0,mx=0;
    for(int i=0;i<n;i++){
        if(v[i]>mx){
            mx=v[i];
            cnt=1;
        }
        else if (v[i]==mx) cnt++;
    }
    cout << cnt << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}