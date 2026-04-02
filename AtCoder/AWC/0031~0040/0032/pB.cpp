#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k,m;
    cin>>n>>k>>m;
    ll cnt=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        cnt += (a+(k+m)-1)/(k+m);
    }
    cout << cnt;
}