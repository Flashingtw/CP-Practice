#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,s,t;
    cin>>n>>s>>t;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(s<v[i]) break;
        else s+=v[i];
    }
    if(s<t) cout << "No";
    else cout << "Yes";
}