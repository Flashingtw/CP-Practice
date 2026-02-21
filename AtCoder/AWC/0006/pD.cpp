#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct ln{
    ll l,r;
    bool operator<(ln other){
        if(l==other.l) return r>other.r;
        return l<other.l;
    }
};
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ln> v(m);
    for(int i=0;i<m;i++) cin>>v[i].l>>v[i].r;
    sort(v.begin(),v.end());
    int cnt=0,cur=0,idx=0;
    while(cur<n){
        ll max_r=-1;
        while(idx<m&&v[idx].l<=cur+1){
            max_r = max(max_r, v[idx].r);
            idx++;
        }
        if(max_r<=cur){
            cout << -1;
            return 0;
        }
        cur = max_r;
        cnt++;
    }
    cout << cnt;
}