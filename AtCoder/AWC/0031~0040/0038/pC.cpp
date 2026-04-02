#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,l,k;
    cin>>n>>l>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll cnt=0;
    ll lmt = min(n,k+1);
    for(int i=0;i<lmt;i++){
        if(l>=v[i]){
            l-=v[i];
            cnt++;
        }
        else break;
    }
    cout << cnt;
}