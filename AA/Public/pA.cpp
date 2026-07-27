#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long l,r;
    cin>>l>>r;
    unsigned long long ans=0;
    for(unsigned long long i=l;i<=r;i++){
        ans+=i;
    }
    cout << ans;
}