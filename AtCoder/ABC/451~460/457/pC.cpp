#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<vector<int>> v(n);
    vector<ll> sz(n);
    for(int i=0;i<n;i++){
        cin>>sz[i];
        v[i].resize(sz[i]);
        for(int j=0;j<sz[i];j++){
            cin>>v[i][j];
        }
    }
    vector<ll> c(n);
    for(ll &a:c) cin>>a;
    
    for(int i=0;i<n;i++){
        if(k>c[i]*sz[i]){
            k -= c[i]*sz[i];
        }
        else{
            k = (k-1)%sz[i];
            cout << v[i][k] << '\n';
            break;
        }
    }
}