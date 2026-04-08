#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        m = (m*a)/100;
    }
    cout << m;
}