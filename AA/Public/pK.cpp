#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<ll> v(n+1),diff(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int g;
    cin>>g;
    ll glo=0;
    ll cnt=n;

    for(int i=1;i<=g;i++){
        int a;
        cin>>a;
        diff[a] += (cnt-1)*i;
        if(diff[a] > v[a]+glo){
            cnt--;
            v[a] = v[a]+glo-diff[a];
        }    
        glo+=i;
        diff[a]+=i;
    }
    for(int i=1;i<=n;i++){
        if(v[i]<0) cout << v[i] << ' ';
        else cout << v[i]+glo-diff[i] << ' ';
    }
}