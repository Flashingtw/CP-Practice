#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    long long ans = (long long)(n+1)*n/2;
    for (int i=0;i<n-1;i++) {
        int val;
        cin>>val;
        ans-=val;
    }
    cout << ans;
}