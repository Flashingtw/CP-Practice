#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll sum=0;
    ll total = (n+1)*n/2;
    for(int i=0;i<n-1;i++){
        int num;
        cin>>num;
        sum+=num;
    }
    cout << total-sum;
}