#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,m,r;
    cin>>n>>m>>r;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        sum+=num;
    }
    cout << sum+(m*r);
}