#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll d[500005];
int main(){
    int n;
    cin>>n;
    set<pll> s={{0,0}};
    d[0] = 1e18;
    ll sum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        auto it_next = s.lower_bound({x,-1});
        auto it_prev = prev(it_next);
        if(it_next!=s.end()) d[i] = min(it_next->first-x,x-it_prev->first);
        else d[i] = x-it_prev->first;
        sum+=d[i];

        int l=it_prev->second;
        ll dis_l= x-it_prev->first;
        if(i==1){
            d[l]=dis_l;
            sum+=d[l];
        }
        else{
            if(dis_l<d[l]){
                sum-=d[l]-dis_l;
                d[l]=dis_l;
            }
        }
        if(it_next!=s.end()){
            int r = it_next->second;
            int dis = it_next->first-x;
             if(dis<d[r]){
                sum-=d[r]-dis;
                d[r]=dis;
            }
        }
        s.insert({x,i});
        cout << sum << ' ';
    }
}