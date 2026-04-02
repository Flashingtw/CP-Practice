#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    ll sum=0;
    vector<ll> d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
        sum+=d[i];
    }
    sort(d.begin(),d.end());
    for(int i=0;i<k;i++){
        sum-=d[i];
    }
    cout << sum;
}