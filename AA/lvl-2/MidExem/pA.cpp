#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll &i:a) cin>>i;
    for(ll &i:b) cin>>i;
    sort(a.begin(),a.end(),greater());
    sort(b.begin(),b.end(),greater());
    int i=0,j=0;
    ll ans=0;
    while(i<n&&j<m&&a[i]>0&&b[j]>0){
        ans+= a[i]*b[j];
        i++,j++;
    }
    i=n-1,j=m-1;
    while(i>=0&&j>=0&&a[i]<0&&b[j]<0){
        ans+= a[i]*b[j];
        i--,j--;
    }
    cout << ans << '\n';
}