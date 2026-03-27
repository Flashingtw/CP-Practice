#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct job{
    ll d,t;
    bool operator<(job a){
        return d*a.t<a.d*t;
    }
};
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<job> a(m);
    for(int i=0;i<m;i++) cin>>a[i].d>>a[i].t;
    sort(a.begin(),a.end());
    sort(v.begin(),v.end());
    int i=0,j=0,ans=0;
    while(i<n&&j<m){
        auto &[d,t] = a[j];
        if(v[i]*t>=d){
            ans++;
            i++,j++;
        }
        else{
            i++;
        }
    }
    cout << ans;
}