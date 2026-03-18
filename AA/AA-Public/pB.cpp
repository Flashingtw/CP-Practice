#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,m;
    cin>>a>>b>>m;
    ll v= 1;
    while(b--){
        v = (v*a) %m;
    }
    cout << v;
}