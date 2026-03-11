#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<ll> A(n),B(n),C(n);
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++) cin>>C[i];
    ll a=A[0]+A[1],b=A[0]+B[1];
    ll c = 0;
    for(int i=2;i<n;i++) {
        c = max(c,b)+C[i];
        b = max(b,a)+B[i];
        a += A[i];
    }
    cout << c;
}