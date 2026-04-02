#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
int pre[N];
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pre[v[i]]++;
        mx = max(mx,v[i]);
    }
    ll ans=0;
    for(int i=1;i<=mx;i++){
        ll sum=0;
        for(int j=i;j<=mx;j+=i){
            sum+=pre[j];
        }
        ans = max(ans,1LL*sum*i);
    }
    cout << ans;
}