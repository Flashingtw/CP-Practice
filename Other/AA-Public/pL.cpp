#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1),cnt(5e5+5),ans(q);
    vector<vector<pii>> ev_l(n+1),ev_r(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=0;i<q;i++){
        int l,r,x;
        cin>>l>>r>>x;
        ev_l[l].push_back({i,x});
        ev_r[r].push_back({i,x});
    }
    for(int i=1;i<=n;i++){
        for(auto &[id,x]:ev_l[i]){
            ans[id]-=cnt[x];
        }
        cnt[v[i]]++;
        for(auto &[id,x]:ev_r[i]){
            ans[id]+=cnt[x];
        }
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
}