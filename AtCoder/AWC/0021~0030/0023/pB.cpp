#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n;
    cin>>n;
    ll cur=0;
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        cur+=a;
        cur-= min(cur,b);
    }
    ll num;
    cin>>num;
    cout << cur+num;
}