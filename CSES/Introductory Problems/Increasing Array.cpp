#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,mx=0;
    cin>>n;
    long long ans=0;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]>mx) mx=v[i];
        else ans+= mx-v[i];
    }
    cout << ans;
}