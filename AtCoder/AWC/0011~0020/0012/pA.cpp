#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    long long ans=0;
    vector<long long> h(n),c(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        if(h[i]<=t) ans+=c[i];
    }
    cout << ans;
}