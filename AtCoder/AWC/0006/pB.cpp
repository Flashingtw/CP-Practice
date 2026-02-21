#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll n,k,t;
    cin>>n>>k>>t;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll d,r;
        cin>>d>>r;
        if(r>=d*k) sum+=r;
    }
    if(sum<t) cout << "No";
    else cout << "Yes";
}