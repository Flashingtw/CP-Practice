#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll dist(pii a,pii b){
    auto [x1,y1]=a;
    auto [x2,y2]=b;
    ll x = x1-x2,y=y1-y2;
    return (x*x)+y*y;
}
int main(){
    ll n,r;
    cin>>n>>r;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x,y,p,q;
        cin>>x>>y>>p>>q;
        if(dist({x,y},{p,q})<=r*r){
            cnt++;
        }
    }
    cout << cnt;
}