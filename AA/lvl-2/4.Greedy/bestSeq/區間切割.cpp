#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,s;
    cin>>n>>s;
    vector<ll> v(n);
    for(ll &a:v) cin>>a;
    ll cur=0,cnt=1;    
    for(int i=0;i<n;i++){
        cur+=v[i];
        if(cur>s){
            cur=v[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}