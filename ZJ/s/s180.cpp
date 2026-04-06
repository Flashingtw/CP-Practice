#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct event{
    int t;
    int type;
    bool operator<(event oth){
        if(t==oth.t) return type<oth.type;
        return t<oth.t;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    vector<event> ev;
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        ev.push_back({s,1});
        ev.push_back({e+1,-1});
    }
    sort(ev.begin(),ev.end());
    int idx=0;
    ll ans=0;
    int cur=0;
    for(auto [t,typ]:ev){
        if(idx>=n) break;
        while(idx<n&&v[idx]<t){
            ans+=cur;
            idx++;
        }
        cur+=typ;
    }
    cout << ans;
}