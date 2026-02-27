#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<int> a(7);
    for(int i=0;i<7;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=0;i<7;i++){
        int n;
        cin>>n;
        ans += a[i]*n;
    }
    cout << ans;
}