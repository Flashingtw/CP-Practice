#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct ln{
    ll l, r;
};
int main(){
    ll n,l;
    cin>>n>>l;
    vector<ln> v(n);
    for(int i=0;i<n;i++){
        ll x,r;
        cin>>x>>r;
        v[i] = {x-r,x+r};
    }
    sort(v.begin(),v.end(),[&](ln &a,ln &b){if(a.l==b.l) return a.r>b.r; else return a.l<b.l;});
    ll cur=0;
    bool chk=true;
    for(int i=0;i<n;i++){
        if(v[i].l>cur){
            chk=false;
            break;
        }
        else{
            cur = max(cur,v[i].r);
        }
    }
    cout << (chk&&cur>=l?"Yes":"No");
}