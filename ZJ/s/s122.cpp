#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll v[200005];
bool sp[200005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,h;
    cin>>n>>h;
    queue<pii> q;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(i>=h){
            q.push({v[i],i});
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        sp[num-1]=1;
    }
    priority_queue<pii,vector<pii>,greater<pii>> special,normal;
    for(int i=0;i<h;i++){
        if(sp[i]){
            special.push({v[i],i});
        }
        else{
            normal.push({v[i],i});
        }
    }
    vector<ll> temp;
    ll time=0;
    for(int i=0;i<2*n;i++){
        if(!special.empty()){
            time+= special.top().first;
            q.push(special.top());
            special.pop();
            temp.push_back(time);
        }
        else{
            time+= normal.top().first;
            q.push(normal.top());
            normal.pop();
        }
        pii t = q.front();
        q.pop();
        if(sp[t.second]){
            special.push(t);
        }
        else{
            normal.push(t);
        }
    }
    int s = min(h-1,n-k);
    ll base_t = time;
    time=0;
    vector<ll> cyc;
    for(int i=0;i<n-s;i++){
        if(!special.empty()){
            time+= special.top().first;
            q.push(special.top());
            special.pop();
            cyc.push_back(time);
        }
        else{
            time+= normal.top().first;
            q.push(normal.top());
            normal.pop();
        }
        pii t = q.front();
        q.pop();
        if(sp[t.second]){
            special.push(t);
        }
        else{
            normal.push(t);
        }
    }
    int qu;
    cin>>qu;
    while(qu--){
        ll t;
        cin>>t;
        if(t<base_t){
            cout << (upper_bound(temp.begin(),temp.end(),t)-temp.begin()) << '\n';
        }
        else{
            ll ans = temp.size();
            ll _t = t-base_t;
            ll cy = _t/time;
            ans += cy*cyc.size();
            ll __t = _t%time;
            cout << ans+(upper_bound(cyc.begin(),cyc.end(),__t)-cyc.begin()) << '\n';
        }
    }
}