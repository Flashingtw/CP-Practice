#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<n/2;i++){
        if(abs(v[i]-v[n-i-1])>k-1) sum+=abs(v[i]-v[n-i-1])-(k-1);
    }
    cout << sum;
}