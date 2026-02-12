#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    long long k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        if(a*b>=k) ans++;
    }
    cout << ans;
}