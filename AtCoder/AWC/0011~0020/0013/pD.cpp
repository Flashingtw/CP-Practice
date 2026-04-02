#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
vector<ll> dir[11];
int n,m;
ll solve(int d){
    sort(dir[d].begin(),dir[d].end());
    ll t=0;
    for(int i=0;i<n;i++){
        t+= dir[d][i]*(2*i-n+1);
    }
    return t;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++) dir[i].resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dir[j][i];
        }
    }
    ll ans=0;
    for(int i=0;i<m;i++){
       ans+=solve(i); 
    }
    cout << ans;
}