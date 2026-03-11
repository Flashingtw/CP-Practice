#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,d,k;
    cin>>n>>d>>k;
    int cnt=0;
    for(int i=0;i<n;i++){
        ll w;
        cin>>w;
        if(w-(d*k)>0) cnt++;
    }
    cout << cnt;
}