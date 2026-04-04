#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> c3,c7;
    long long ans=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%7==0) c7[v[i]]++;
        if(v[i]%3==0) c3[v[i]]++;
        if(v[i]%5==0) {
            ll ai = v[i]/5*7;
            ll ak = v[i]/5*3;
            ans+= c7[ai]*c3[ak];
        }
    }
    c3.clear();c7.clear();
    for(int i=n-1;i>=0;i--){
        if(v[i]%7==0) c7[v[i]]++;
        if(v[i]%3==0) c3[v[i]]++;
        if(v[i]%5==0) {
            ll ai = v[i]/5*7;
            ll ak = v[i]/5*3;
            ans+= c7[ai]*c3[ak];
        }
    }
    cout << ans;
}