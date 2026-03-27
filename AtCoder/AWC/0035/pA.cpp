#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> d(n+1);
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        d[v]+=w;
        d[u]-=w;
    }
    ll mx=d[1],idx=1;
    for(int i=1;i<=n;i++){
        if(d[i]>mx){
            idx=i;
            mx=d[i];
        }
    }
    cout << idx;
}