#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    cout << (1<<n)-1 << "\n";
    ll a=1,b=2+(n&1);
    for (ll i = 1;i<(1<<n);i++){
        cout << a << " " << b <<"\n";
        ll c = __builtin_ctzll(i+(i&1))&1;
        if (c|i&1^1)a=6-a-b;
        if (c|i&1)b=6-a-b;
    }
}