#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;
    ll ans=0;
    for(int i=1;i<n;i++){
        ans = gcd(ans,abs(a[i]-a[0]));
    }
    cout << (ans==1?2:1) << '\n';
}