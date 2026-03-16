#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,t,e;
    cin>>n>>t>>e;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if((sum+v[i])*t<=e){
            cnt++;
            sum+=v[i];
        }
        else break;
    }
    cout << cnt;
}