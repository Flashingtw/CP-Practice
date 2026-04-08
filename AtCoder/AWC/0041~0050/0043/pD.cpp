#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    ll total=0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        total+=v[i];
    }
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+= total-v[i]*(n-i);
        total-=v[i];
    }
    cout << sum;
}